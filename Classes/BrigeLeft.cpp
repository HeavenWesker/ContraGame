//
//  BriageLeft.cpp
//  ContraGame
//
//  Created by Heaven on 5/13/15.
//
//

#include "BrigeLeft.h"

bool BrigeLeft::init(){
    Sprite::init();
    sprite = Sprite::create("building/briageLeft1.png");
    sprite->setAnchorPoint(Vec2(0,1));
    sprite->setScale(2.31, 1.7);
    addChild(sprite);
    return true;
}