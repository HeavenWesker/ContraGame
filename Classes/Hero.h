//
//  Hero.h
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#ifndef __ContraGame__Hero__
#define __ContraGame__Hero__

#include <stdio.h>
#include "cocos2d.h"
using namespace::cocos2d;

class Hero: public Sprite{
public:
    CREATE_FUNC(Hero);
    bool init();
    void idle();
    bool direction;
};


#endif /* defined(__ContraGame__Hero__) */
