//
//  Bullet.cpp
//  ContraGame
//
//  Created by Heaven on 5/11/15.
//
//

#include "Bullet.h"
#include "math.h"
bool Bullet::init(){
    Sprite::init();
    auto bullet = Sprite::create("bullet.png");
    addChild(bullet);
    speed = 10;
    radian = 0;
    return true;
}
void Bullet::update(float dt){
    float speedX = speed * cos(radian);
    float speedY = speed * sin(radian);
    setPosition(getPositionX()+speedX, getPositionY()+speedY);
}
