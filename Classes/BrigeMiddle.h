//
//  BriageMiddle.h
//  ContraGame
//
//  Created by Heaven on 5/13/15.
//
//

#ifndef __ContraGame__BriageMiddle__
#define __ContraGame__BriageMiddle__

#include <stdio.h>
#include "cocos2d.h"
using namespace::cocos2d;
class BrigeMiddle:public Sprite{
public:
    bool init();
    Action *action;
    Action *destroyAction;
    Sprite *sprite;
    CREATE_FUNC(BrigeMiddle);
};

#endif /* defined(__ContraGame__BriageMiddle__) */
