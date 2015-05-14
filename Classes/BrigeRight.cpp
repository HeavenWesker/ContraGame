//
//  BriageRight.cpp
//  ContraGame
//
//  Created by Heaven on 5/13/15.
//
//

#include "BrigeRight.h"
bool BrigeRight::init(){
    Sprite::init();
    sprite = Sprite::create("building/briageMiddle1.png");
    sprite->setAnchorPoint(Vec2(0,1));
    sprite->setScale(2.31, 1.7);
    addChild(sprite);
    return true;
}
