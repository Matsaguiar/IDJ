#include "../include/Minion.hpp"
#include "../include/Game.hpp"

Minion::Minion(GameObject& associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated){ 
    Sprite* sprite = new Sprite(associated, "./recursos/img/minion.png");
    associated.AddComponent(sprite);
    double scale = (double)rand() / (double)(RAND_MAX/0.5)+1;
    // double scale = 2;
    sprite -> SetScale(scale, scale);
    this -> alienCenter = alienCenter;
    if(shared_ptr<GameObject> go = alienCenter.lock()){
        associated.box.x = go->box.GetCoordenadasCentro().x+200-associated.box.w/2;
        associated.box.y = go->box.GetCoordenadasCentro().y+0-associated.box.h/2;
    } 
    arc = arcOffsetDeg;
    associated.angleDeg = arcOffsetDeg;
}

void Minion::Update(float dt) {
    Vec2 centro = alienCenter.lock()->box.GetCoordenadasCentro();
    Vec2 aux = Vec2(100, 0).Rotacao(arc) + centro;
    arc += 2*M_PI/360*dt*64;

    associated.box.x = aux.x-associated.box.w/2;
    associated.box.y = aux.y-associated.box.h/2;

    Vec2 pos = associated.box.GetCoordenadasCentro();
    associated.angleDeg = (pos.inclinacao(centro)*360)/(2*M_PI);
}

void Minion::Render() {}

bool Minion::Is(string type) {
    return type == "Minion";
}

void Minion::Shoot(Vec2 target) {
    Sprite* sprite = (Sprite*)associated.GetComponent("Sprite");
    Vec2 pos = Vec2(associated.box.GetCoordenadasCentro().x + associated.box.w/2 - sprite->GetWidth()/2, associated.box.GetCoordenadasCentro().y - sprite->GetHeight()/2);
    float ang = pos.inclinacao(target);
    Vec2 aux = Vec2(sprite->GetWidth()/2, 0).Rotacao(ang)+pos;
    GameObject *go = new GameObject();

    go -> box.x = aux.x;
    go -> box.y = aux.y;
    go -> angleDeg = ang*180/M_PI;

    Bullet* bullet = new Bullet(*go, ang, 512, 50, 1024, "./recursos/img/minionbullet1.png");
    go -> AddComponent(bullet);
    State* instance = &Game::GetInstance().GetState();
    instance -> AddObject(go);
}

void Minion::Start(){
    
}