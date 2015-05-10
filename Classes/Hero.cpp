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
    this->removeAllChildren();
    auto sprite = Sprite::create("hero/idle.png");
    sprite->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(sprite);
    sp = sprite;
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
            movingRight = true;
            moveAnimation();
            break;
        case 26://left key
            movingLeft = true;
            moveAnimation();
            break;
        default:
            break;
    }
}
void Hero::onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event){
    switch (int(code)) {
        case 27://right key
            movingRight = false;
            sp->stopAction(movingAction);
            idle();
            break;
        case 26://left key
            movingLeft = false;
            sp->stopAction(movingAction);
            idle();
            break;
        default:
            break;
    }
}

void Hero::moveLeft(float dt){
    float d = 100 * dt;
    this->setScaleX(directionRight? -1: 1);
    directionRight = false;
    setPositionX(getPositionX()-d);
}
void Hero::moveRight(float dt){
    float d = 100 * dt;
    this->setScaleX(directionRight? -1: 1);
    directionRight = true;
    setPositionX(getPositionX()+d);
}
void Hero::update(float dt){
    if (movingRight) {
        moveRight(dt);
    }
    if (movingLeft) {
        moveLeft(dt);
    }
}
void Hero::moveAnimation(){
    Vector<SpriteFrame*> allFrames;
    for (int i = 0; i < 3; i++) {
        char txt[100] = {};
        sprintf(txt, "hero/run_left000%d.png", i+1);
        SpriteFrame * spriteFrame = SpriteFrame::create(txt, Rect(0,0,55,55));
        allFrames.pushBack(spriteFrame);
    }
    CCLOG("%zd",allFrames.size());
    Animation* animation = Animation::createWithSpriteFrames(allFrames, 0.2);
    movingAction = sp->runAction(RepeatForever::create(Animate::create(animation)));
}