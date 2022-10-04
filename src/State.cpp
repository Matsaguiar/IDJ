#include "../include/State.hpp"
 
State::State(){
	started = false;
    GameObject* go = new GameObject();
	
	GameObject* mapGO = new GameObject();
	Sprite* sprite = new Sprite(*mapGO, "./recursos/img/ocean.jpg");

    mapGO->AddComponent(sprite);

	CameraFollower* cf = new CameraFollower(*mapGO);
	mapGO->AddComponent(cf);

	mapGO->box.x = Camera::pos.x;
	mapGO->box.y = Camera::pos.y;
	objectArray.emplace_back(mapGO);

	TileSet* tileSET = new TileSet(64, 64, "./recursos/img/tileset.png");
	TileMap* tileMAP = new TileMap(*go, "./recursos/map/tileMap.txt", tileSET);
	
	go->AddComponent(tileMAP);
	go->box.x = 0;
	go->box.y = 0;
	objectArray.emplace_back(go);
    
    GameObject* AlienGO = new GameObject();
	AlienGO -> box.x = 512 - AlienGO -> box.w/2;
	AlienGO -> box.y = 300 - AlienGO -> box.h/2;

	Alien* alien = new Alien(*AlienGO, 5);
	AlienGO -> AddComponent(alien);

	objectArray.emplace_back(AlienGO);

	quitRequested = false;
	started = false;
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){
    music.Open("./recursos/audio/stageState.ogg");
}

void State::Update(float dt){
    InputManager inputManager = InputManager::GetInstance();

    Camera::Update(dt);

    quitRequested = inputManager.KeyPress(ESCAPE_KEY) || inputManager.QuitRequested();

    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i].get()->Update(dt);
    }

    for(int i = 0; i < objectArray.size(); i++) {
        if (objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render(){
   	for(unsigned int i = 0; i < objectArray.size(); i++){
		objectArray[i].get() -> Render();
	}
}

State::~State(){
    objectArray.clear();
}

/*void State::Input(){
    SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.dentroRect( {(float)mouseX, (float)mouseY} ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).Rotacao( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}*/

void State::AddObject(int mouseX, int mouseY){
    GameObject *go = new GameObject();
    
    Sprite *sprite = new Sprite(*go, "./recursos/img/penguinface.png");
    go -> AddComponent(sprite);

    go -> box.x = mouseX - go->box.w/2 + Camera::pos.x;
	go -> box.y = mouseY - go->box.h/2 + Camera::pos.y;

    Sound *sound = new Sound(*go, "./recursos/audio/boom.wav");
    go->AddComponent(sound);

    Face *face = new Face(*go);
    go->AddComponent(face);

    objectArray.emplace_back(go);
}

void State::Start() {
    LoadAssets();
    music.Play();
    for (auto &i : objectArray) {
        i->Start();
    }
    started = true;
}

weak_ptr<GameObject> State::AddObject(GameObject *go) {
    shared_ptr<GameObject> gameObject(go);
    objectArray.push_back(gameObject);
    if(started){
        gameObject->Start();
    }
    return weak_ptr<GameObject>(gameObject);
}

weak_ptr<GameObject> State::GetObjectPtr(GameObject *go) {
    for (auto &i : objectArray) {
        if(i.get() == go){
            return weak_ptr<GameObject>(i);
        }
    }
    return weak_ptr<GameObject>();
}
