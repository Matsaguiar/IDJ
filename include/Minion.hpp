#ifndef MINION_HPP
#define MINION_HPP

#include "SDL_include.h"
#include "Component.hpp"
#include <string>
#include "Bullet.hpp"

using namespace std;

class Minion : public Component{
public:
    Minion(GameObject& associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);

    void Shoot(Vec2 target);
    void Start();
    void Update(float dt) override;
    void Render();
    bool Is(string type);

private:
    //GameObject& alienCenter;
    weak_ptr<GameObject> alienCenter; //Matem a referencia ponteiro construtor
    float arc;
};

#endif