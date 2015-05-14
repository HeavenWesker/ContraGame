//
//  BriageRight.h
//  ContraGame
//
//  Created by Heaven on 5/13/15.
//
//

#ifndef __ContraGame__BrigeRight__
#define __ContraGame__BrigeRight__

#include <stdio.h>
#include "cocos2d.h"
using namespace::cocos2d;
class BrigeRight:public Sprite{
public:
    bool init();
    Action *action;
    Action *destroyAction;
    Sprite *sprite;
    CREATE_FUNC(BrigeRight);
};

#endif /* defined(__ContraGame__BrigeRight__) */
