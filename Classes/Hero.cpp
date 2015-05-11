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
    isDown = false;
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
            if (!isJumping) {
                moveAnimation();
            }
            break;
        case 26://left key
            movingLeft = true;
            if (!isJumping) {
                moveAnimation();
            }
            break;
        case 29://down
            if (!isJumping) {
                down();
                isDown = true;
            }
            break;
        case 28://jump
            if (!isJumping) {
                jump();
                originY = this->getPositionY();
                speedY = 6;
                gravaty = -0.2;
                isJumping = true;
            }
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
            if (!isJumping) {
                idle();
            }
            break;
        case 26://left key
            movingLeft = false;
            sp->stopAction(movingAction);
            if (!isJumping) {
                idle();
            }
            break;
        case 29://down
            isDown = false;
            if (!isJumping) {
                idle();
            }
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
    if (isJumping) {
        setPositionY(getPositionY()+speedY);
        speedY+=gravaty;
        if (getPositionY()<originY) {
            setPositionY(originY);
            isJumping = false;
            sp->stopAction(movingAction);
            idle();
        }
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
    Animation* animation = Animation::createWithSpriteFrames(allFrames, 0.2);
    movingAction = sp->runAction(RepeatForever::create(Animate::create(animation)));
}
void Hero::down(){
    this->removeAllChildren();
    auto sprite = Sprite::create("hero/down.png");
    sprite->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(sprite);
    sp = sprite;
    this->setScaleX(directionRight? -1: 1);
    
}
void Hero::jump(){
    this->stopAction(movingAction);
    Vector<SpriteFrame*> allFrames;
    for (int i = 0; i < 3; i++) {
        char txt[100] = {};
        sprintf(txt, "hero/jump000%d.png", i+1);
        SpriteFrame * spriteFrame = SpriteFrame::create(txt, Rect(0,0,55,55));
        allFrames.pushBack(spriteFrame);
    }
    Animation* animation = Animation::createWithSpriteFrames(allFrames, 0.2);
    movingAction = sp->runAction(RepeatForever::create(Animate::create(animation)));
}