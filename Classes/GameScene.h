//
//  GameScene.h
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#ifndef ContraGame_GameScene_h
#define ContraGame_GameScene_h

#include "Hero.h"
using namespace cocos2d;
class GameScene : public Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    void update(float dt); //delta time
    Hero* hero;
};


#endif
