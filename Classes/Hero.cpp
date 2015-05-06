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
    directionRight = true;
    movingRight = false;
    movingLeft = false;
    idle();
    ListenKeyboardEvent();
    return true;
}
void Hero::idle(){
    auto sprite = Sprite::create("hero/idle.png");
    sprite->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(sprite);
    this->setScaleX(directionRight? -1: 1);
}
void Hero::ListenKeyboardEvent(){
    this->_eventDispatcher->removeAllEventListeners();
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressedOwn, this);
    listener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleasedOwn, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void Hero::onKeyPressedOwn(EventKeyboard::KeyCode code, Event* event){
    switch (int(code)) {
        case 27://right key
//            moveRight(0.1);
            movingRight = true;
            break;
        case 26://left key
//            moveLeft(0.1);
            movingLeft = true;
            break;
            
        default:
            break;
    }
}
void Hero::onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event){
    switch (int(code)) {
        case 27://right key
//            moveRight(0.1);
            movingRight = false;
            break;
        case 26://left key
//            moveLeft(0.1);
            movingLeft = false;
            break;
            
        default:
            break;
    }
}

void Hero::moveLeft(float dt){
    float d = 100 * dt;
    setPositionX(getPositionX()-d);
}
void Hero::moveRight(float dt){
    float d = 100 * dt;
    directionRight = false;
    setPositionX(getPositionX()+d);
}
void Hero::update(float dt){
    CCLOG("Hero::update %f", dt);
    if (movingRight) {
        moveRight(dt);
    }
    if (movingLeft) {
        moveLeft(dt);
    }
    
}