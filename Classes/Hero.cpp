//
//  Hero.cpp
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#include "Hero.h"

bool Hero::init(){
    Sprite::init();
    direction = true;
    idle();
    return true;
}
void Hero::idle(){
    auto sprite = Sprite::create("hero/idle.png");
    sprite->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(sprite);
    this->setScaleX(direction? -1: 1);
}