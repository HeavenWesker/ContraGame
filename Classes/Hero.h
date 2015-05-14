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
    bool directionRight;
    bool movingRight;
    bool movingLeft;
    void ListenKeyboardEvent();
    void onKeyPressedOwn(EventKeyboard::KeyCode code, Event* event);
    void onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event);
    void moveRight(float dt);
    void moveLeft(float dt);
    void update(float dt);
    void moveAnimation();
    Sprite *sp;
    Action *movingAction;
    bool isDown;
    void down();
    void jump();
    bool isJumping;
    float speedY;
    float gravaty;
    float originY;
    float speedX;
    void gravatyEffect(float dt);
};


#endif /* defined(__ContraGame__Hero__) */
