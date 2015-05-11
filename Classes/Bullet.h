//
//  Bullet.h
//  ContraGame
//
//  Created by Heaven on 5/11/15.
//
//

#ifndef __ContraGame__Bullet__
#define __ContraGame__Bullet__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Bullet:public Sprite{
public:
    CREATE_FUNC(Bullet);
    bool init();
    void update(float dt);
    float speed;
    float radian;
};

#endif /* defined(__ContraGame__Bullet__) */
