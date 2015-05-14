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
//#include "GameScene.h"
using namespace cocos2d;
class Bombman:public Sprite{
public:
    CREATE_FUNC(Bombman);
    bool init();
    void update(float dt);
    void moveLeft(float dt);
    Action *movingAction;
    Action *dieAction;
    void die();
    void gravatyEffect(float dt);
    float originY;
    float speedY;
    float gravaty = -0.2;
    bool isJumping;
    int dieTimeout = -1;
    bool hittable = true;
};
extern Vector<Bombman*> bombmans;

#endif /* defined(__ContraGame__Bombman__) */
