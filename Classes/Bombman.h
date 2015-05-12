//
//  Bombman.h
//  ContraGame
//
//  Created by Heaven on 5/11/15.
//
//

#ifndef __ContraGame__Bombman__
#define __ContraGame__Bombman__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Bombman:public Sprite{
public:
    CREATE_FUNC(Bombman);
    bool init();
    void update(float dt);
    void moveLeft(float dt);
    Action *movingAction;
    void die();
};

#endif /* defined(__ContraGame__Bombman__) */
