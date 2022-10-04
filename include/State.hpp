#ifndef STATE_HPP
#define STATE_HPP
 
#define INCLUDE_SDL
#include "SDL_include.h"

#include "Bits/stdc++.h"
#include <memory>
#include <math.h>

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Music.hpp"
#include "Face.hpp"
#include "Rect.hpp"
#include "Vec2.hpp"
#include "TileMap.hpp"
#include "CameraFollower.hpp"
#include "Alien.hpp"

using namespace std;

class State{
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    void Start();
    weak_ptr<GameObject> AddObject(GameObject* go);
    weak_ptr<GameObject> GetObjectPtr(GameObject* go);

private:
    Music music;
    bool quitRequested;
    bool started;

    void Input();
    //void AddObject(int mouseX, int mouseY);
    //vector<unique_ptr<GameObject>> objectArray;
    vector <shared_ptr<GameObject>> objectArray;
};

#endif