#include "../include/Bullet.hpp"
#include "../include/Sprite.hpp"

Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite) : Component(associated){
    Sprite* spritee = new Sprite(associated, sprite);
    associated.AddComponent(spritee);

    this -> speed = Vec2(1, 0);
    this -> speed = this -> speed.Rotacao(angle)*speed;
    distanceLeft = maxDistance;
    this -> damage = damage;
}

int Bullet::GetDamage(){
    return damage;
}

bool Bullet::Is(string type){
    return type == "Bullet";
}

void Bullet::Update(float dt){
    associated.box += speed * dt;
    distanceLeft -= (speed * dt).magnitude();
    if(distanceLeft < 0){
        associated.RequestDelete();
    }
}

void Bullet::Render(){
    
}