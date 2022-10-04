#include "../include/Alien.hpp"
#include "../include/Game.hpp"

Alien::Alien(GameObject& associated, int nMinions) : Component(associated){
    Sprite* sprite = new Sprite(associated, "./recursos/img/alien.png");
    associated.AddComponent(sprite);
    hp = 50;
    //hp = 100;
    speed = Vec2(0, 0);
    this -> nMinions = nMinions;
}

Alien::~Alien(){
    for (auto &i : minionArray) {
        i.lock()->RequestDelete();
    }
    minionArray.clear();
}

void Alien::Start(){
    for(int i = 0; i < nMinions; i++){
        State* instance = &Game::GetInstance().GetState();
        GameObject* go = new GameObject();
        weak_ptr<GameObject> alienCenter = instance -> GetObjectPtr(&associated);
        Minion *minion = new Minion(*go, alienCenter, (M_PI*(1+2*i*360/nMinions))/360);
        go -> AddComponent(minion);
        minionArray.push_back(instance -> AddObject(go));
    }
}

void Alien::Render(){

}

void Alien::Update(float dt){
    InputManager inputManager = InputManager::GetInstance();
    auto posX = (int)(inputManager.GetMouseX() + Camera::pos.x), posY = (int)(inputManager.GetMouseY() + Camera::pos.y);

    if(inputManager.MousePress(LEFT_MOUSE_BUTTON)){
        taskQueue.push(*new Action(Action::SHOOT, posX , posY));
    } else if(inputManager.MousePress(RIGHT_MOUSE_BUTTON)){

        //impede de acumular eventos na fila, sobrescrevendo sempre que há um evento
        while(!taskQueue.empty()){
            taskQueue.pop();
        }
        taskQueue.push(*new Action(Action::MOVE, posX, posY));
    }

    if(!taskQueue.empty()){
        auto action = taskQueue.front();

        if(action.type == Action::MOVE){
            Vec2 deltaX = {500 * dt, 0};
            Vec2 calculado = action.pos - Vec2(associated.box.x + (associated.box.w/2), associated.box.y + (associated.box.h/2));
            Vec2 real = deltaX.Rotacao(calculado.InclX());

            //Distancia minima para o Alien nao chegar ao destino no proximo frame
            if(calculado.magnitude() < real.magnitude()){
                associated.box += calculado;
                taskQueue.pop();
            } else {
                associated.box += real;
            }

        } else if(action.type == Action::SHOOT){
            auto target = InputManager::GetInstance().GetMouse();

            //Pega o minion com a menor distância do alvo
            const shared_ptr<GameObject> &ptr = minionArray[NearestMinion(target)].lock();
            auto minion = (Minion*)(ptr->GetComponent("Minion"));
            minion->Shoot(target);

            taskQueue.pop();
        }
    }

    associated.angleDeg += -2;

    if(hp <= 0){
        associated.RequestDelete();
    }
}

bool Alien::Is(string type){
    return type == "Alien";
}

int Alien::ClosestMinion(Vec2 pos){
    int minion;
    float min_distance = INT32_MAX;
    for(unsigned int i = 0; i < minionArray.size(); i++){
        if(shared_ptr<GameObject> go = minionArray[i].lock()){
            Vec2 aux = Vec2(go -> box.x, go -> box.y);
            float dist = aux.distancia(pos);
            if(dist <= min_distance){
                min_distance = dist;
                minion = i;
            }
        }
    }
    return minion;
}

Alien::Action::Action(ActionType type, float x, float y){
    pos.x = x;
    pos.y = y;
    this -> type = type;
}