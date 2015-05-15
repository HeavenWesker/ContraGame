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
#include "Bullet.h"
#include "Bombman.h"
#include "BrigeLeft.h"
#include "BrigeMiddle.h"
#include "BrigeRight.h"
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
    void fire();
    void moveBullets(float dt);
    Vector<Bullet*> bullets;
    bool isFiring;
    void ListenKeyboardEvent();
    void onKeyPressedOwn(EventKeyboard::KeyCode code, Event* event);
    void onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event);
    int count;
    bool outScreen(Node* node);
    void addBombman();
    void moveBombmans(float dt);
    int addBombmanCount;
    void checkHited();
    Sprite* map;
    void addPlatform();
    Sprite *brige_1_left;
    Sprite *brige_1_middle_1;
    Sprite *brige_1_middle_2;
    Sprite *brige_1_right;
    
    Sprite *brige_2_left;
    Sprite *brige_2_middle_1;
    Sprite *brige_2_middle_2;
    Sprite *brige_2_right;
    
    Sprite *boos;
    void addBrige();
    void gameOver();
    int life = 10;
    int boosLife = 3;
    Action *boosDieAction;
    void addBoos();
    void youWin();
    int boosDieTimeOut = -1;
    int winTimeOut = -1;
    
};
bool brige_1_1;
bool brige_1_2;
bool brige_1_3;
bool brige_1_4;

bool brige_2_1;
bool brige_2_2;
bool brige_2_3;
bool brige_2_4;
Vector<Bombman*> bombmans;

//bool GameScene::brige_1_1 = true;
//bool GameScene::brige_1_2 = true;
//bool GameScene::brige_1_3 = true;
//bool GameScene::brige_1_4 = true;
//bool GameScene::brige_2_1 = true;
//bool GameScene::brige_2_2 = true;
//bool GameScene::brige_2_3 = true;
//bool GameScene::brige_2_4 = true;


#endif
