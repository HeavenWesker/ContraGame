//
//  BriageLeft.h
//  ContraGame
//
//  Created by Heaven on 5/13/15.
//
//

#ifndef __ContraGame__BriageLeft__
#define __ContraGame__BriageLeft__

#include <stdio.h>
#include "cocos2d.h"
using namespace::cocos2d;
class BrigeLeft:public Sprite{
public:
    bool init();
    Action *action;
    Action *destroyAction;
    Sprite *sprite;
    CREATE_FUNC(BrigeLeft);
};

#endif /* defined(__ContraGame__BriageLeft__) */
