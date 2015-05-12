//
//  Bombman.cpp
//  ContraGame
//
//  Created by Heaven on 5/11/15.
//
//

#include "Bombman.h"
#define PI 3.141592653
bool Bombman::init(){
    Sprite::init();
    this->setAnchorPoint(Vec2(0.5,0));
    Vector<SpriteFrame*> allFrames;
    for (int i = 0; i < 2; i++) {
        char txt[100] = {};
        sprintf(txt, "bombman/bombman_runleft000%d.png", i+1);
        SpriteFrame * spriteFrame = SpriteFrame::create(txt, Rect(0,0,35,48));
        allFrames.pushBack(spriteFrame);
    }
    allFrames.pushBack(SpriteFrame::create("bombman/bombman_idle.png", Rect(0,0,35,48)));
    Animation* animation = Animation::createWithSpriteFrames(allFrames, 0.2);
    movingAction = this->runAction(RepeatForever::create(Animate::create(animation)));
    return true;
}
void Bombman::update(float dt){
    moveLeft(dt);
}
void Bombman::moveLeft(float dt){
    float d = 100 * dt;
    setPositionX(getPositionX()-d);
}
void Bombman::die(){
    this->removeAllChildren();
    auto sprite = Sprite::create("bombman_idle.png");
    sprite->setRotation(PI/2);
}