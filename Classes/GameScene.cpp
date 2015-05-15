//
//  GameScene.cpp
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#include <stdio.h>
#define PI 3.141592653

#include "GameScene.h"
#include "MainScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    map = Sprite::create("bg.jpg");
//    map = Sprite::create("bg_2.jpg");
    map->setAnchorPoint(Vec2(0,0));
    this->addChild(map);
    addBrige();
    addBoos();
    //add platform
//    addPlatform();
    //add hero
    hero = Hero::create();
    hero->setPosition(120, 200);
    map->addChild(hero);
//    this->addChild(win);
    
//    auto bullet = Bullet::create();
//    bullet->setPosition(150, 200);
//    map->addChild(bullet);
    addBombmanCount = 0;
    for (int i =0; i < life; i++) {
        auto lifeSprite = Sprite::create("life.png");
        lifeSprite->setAnchorPoint(Vec2(0,0));
        lifeSprite->setScale(0.5,0.5);
        lifeSprite->setPosition(450-i*60, 450);
        addChild(lifeSprite);
        lifeSprites.pushBack(lifeSprite);
    }
    
//    this->schedule(schedule_selector(GameScene::update), 0.01);
    isFiring = false;
    ListenKeyboardEvent();
    scheduleUpdate();

    return true;
}
void GameScene::update(float dt){
    if (pause) {
        CCLOG("PAUSE");
        return;
    }
    if (winTimeOut != -1) {
        CCLOG("WINTIMEOUT%d", winTimeOut);
        winTimeOut += 1;
        if (winTimeOut == 100) {
            gameOver();
        }
    }
//    CCLOG("hero position:%f", hero->getPositionX());
//    CCLOG("map position:%f", map->getPositionX());
    if (isFiring) {
        if (count % 10 == 0) {
            fire();
        }
    }
    count ++;
    if (addBombmanCount % 75 == 0) {
        addBombman();
    }
    addBombmanCount++;
    
    hero->update(dt);
    float heroX = hero->getPositionX();
    float mapX = map->getPositionX();
    if (heroX + mapX > 256 && mapX > -7589+512 && hero->isRunning()) {
        map->setPositionX(map->getPositionX()-dt*hero->speedX);
    }
    if (heroX+mapX<10) {
        hero->setPositionX(-mapX+10);
    }
    if (heroX+mapX>502) {
        hero->setPositionX(7589-10);
    }
    if (boosDieTimeOut != -1 and boosDieTimeOut != 100) {
        boosDieTimeOut += 1;
        CCLOG("BOOSWAIT%d", boosDieTimeOut);
    }else if(boosDieTimeOut == 100){
        boos->stopAction(boosDieAction);
    Sprite *winSprite = Sprite::create("you_win.png");
    winSprite->setAnchorPoint(Vec2(0.5,0.5));
    winSprite->setScale(0.70, 0.70);
    winSprite->setPosition(Vec2(7340,200));
        map->addChild(winSprite);
        if (winTimeOut == -1) {
            winTimeOut = 0;
        }
        boosDieTimeOut += 1;
    }
    moveBullets(dt);
    moveBombmans(dt);
    checkHited();
}

void GameScene::ListenKeyboardEvent(){
//    this->_eventDispatcher->removeAllEventListeners();
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressedOwn, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleasedOwn, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void GameScene::onKeyPressedOwn(EventKeyboard::KeyCode code, Event* event){
    switch (int(code)) {
        case 133://Fire
//            fire();
            isFiring = true;
            count = 0;
            break;
        case 6:
            pause = pause? false : true;
            break;
        default:
            break;
    }
}
void GameScene::onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event){
    switch (int(code)) {
        case 133://Fire
            isFiring = false;
            break;
        case 6:
            break;
        default:
            break;
    }
}
void GameScene::fire(){
//    CCLOG("FIRE");
    auto bullet = Bullet::create();
    bullet->radian = hero->directionRight?0:PI;
    bullet->setPositionY(hero->getPositionY()+(hero->isDown?13:36));
//    bullet->setPositionY(hero->getPositionY()+(hero->movingRight||hero->movingLeft?36:16));
    bullet->setPositionX(hero->getPositionX()+(hero->directionRight?20:-20));
    map->addChild(bullet);
    bullets.pushBack(bullet);
}
void GameScene::moveBullets(float dt){
    for (int i = 0; i < bullets.size(); i++) {
        auto bullet = bullets.at(i);
        bullet->update(dt);
        if (outScreen(bullet)) {
            bullet->removeFromParent();
            bullets.eraseObject(bullet);
//            CCLOG("bullet removed");
            i--;
        }
    }
}
bool GameScene::outScreen(Node* node){
//    if (node->getPositionX()>map->getPositionX() + 600 || node->getPositionX()<map->getPositionX() - 20 ||
//        node->getPositionY()>map->getPositionY() + 600 || node->getPositionY()<map->getPositionY() - 20) {
//        return true;
//    }
    auto positionOnScreen = node->getPositionX()+map->getPositionX();
    if (positionOnScreen< -20 || positionOnScreen> 600) {
        return true;
    }
    return false;
}
void GameScene::addBombman(){
    auto bombman = Bombman::create();
//    bombman->setPosition(600,200);
    bombman->setPosition(600-map->getPositionX(),200);
    map->addChild(bombman);
    bombmans.pushBack(bombman);
}
void GameScene::moveBombmans(float dt){
    for (int i = 0; i < bombmans.size(); i++) {
        auto bombman = bombmans.at(i);
        bombman->update(dt);
        if (outScreen(bombman)) {
            bombman->removeFromParent();
            bombmans.eraseObject(bombman);
//            CCLOG("bombman removed");
            i--;
        }
    }
}
void GameScene::checkHited(){
    for (int i = 0; i<bombmans.size(); i++) {
        auto bombman = bombmans.at(i);
        auto bombmanRect = Rect(bombman->getPositionX(), bombman->getPositionY(), 35, 48);
        for (int j = 0; j<bullets.size(); j++) {
            auto bullet = bullets.at(j);
            auto bulletRect = Rect(bullet->getPositionX(), bullet->getPositionY(), 1, 1);
//            if (std::abs(bombman->getPositionX()-bullet->getPositionX())<20 &&bullet->getPositionY()-bombman->getPositionY()<50) {
            if (bombmanRect.intersectsRect(bulletRect) and bombman->hittable) {
//                bombmans.eraseObject(bombman);
//                bombman->removeFromParent();
////                bombman->die();
//                bullets.eraseObject(bullet);
//                bullet->removeFromParent();
////                CCLOG("Hitted");
//                i--;
//                j--;
                bullets.eraseObject(bullet);
                bullet->removeFromParent();
                bombman->die();
                break;
            }
        }
        auto heroRect = Rect(hero->getPositionX(), hero->getPositionY(),30, 40);
        if((bombmanRect.intersectsRect(heroRect) and bombman->hittable) or hero->getPositionY() <= -50){
            CCLOG("DIE");
            bombman->die();
            //                bombmans.eraseObject(bombman);
            //                bombman->removeFromParent();
            //                hero->setPosition(120-map->getPositionX(), 500);
            hero->setPosition(120-map->getPositionX(), 300);
            CCLOG("ssss%f:%f",hero->getPositionX(),hero->getPositionY());
            life--;
            lifeSprites.at(life)->removeFromParent();
            if (life==0) {
                gameOver();
            }
            //                i--;
        }
        for (int i = 0; i < bullets.size(); i++) {
            auto *bullet = bullets.at(i);
            auto boosRect = Rect(boos->getPositionX(), boos->getPositionY(), 257, 307);
            auto bulletRect = Rect(bullet->getPositionX(),bullet->getPositionY(), 1, 1);
            if (boosRect.intersectsRect(bulletRect)) {
                bullets.eraseObject(bullet);
                bullet->removeFromParent();
                boosLife -= 1;
                if (boosLife == 0) {
                    youWin();
                }
                break;
            }
            
        }
    }
}
void GameScene::addBrige(){
//    brige_1_middle_1 = Sprite::create("building/briageMiddle.gif");
//    brige_1_middle_2 = Sprite::create("building/briageMiddle.gif");
//    brige_1_right = Sprite::create("building/briageRight.gif");
    brige_1_left = BrigeLeft::create();
    brige_1_left->setPosition(1773,200);
    brige_1_1 = true;
    map->addChild(brige_1_left);
    brige_1_middle_1 = BrigeMiddle::create();
    brige_1_middle_1->setPosition(1847,200);
    brige_1_2 = true;
    map->addChild(brige_1_middle_1);
    brige_1_middle_2 = BrigeMiddle::create();
    brige_1_middle_2->setPosition(1921,200);
    brige_1_3 = true;
    map->addChild(brige_1_middle_2);
    brige_1_right = BrigeRight::create();
    brige_1_right->setPosition(1995,200);
    brige_1_4 = true;
    map->addChild(brige_1_right);
    //
    brige_2_left = BrigeLeft::create();
    brige_2_left->setPosition(2439,200);
    brige_2_1 = true;
    map->addChild(brige_2_left);
    brige_2_middle_1 = BrigeMiddle::create();
    brige_2_middle_1->setPosition(2513,200);
    brige_2_2 = true;
    map->addChild(brige_2_middle_1);
    brige_2_middle_2 = BrigeMiddle::create();
    brige_2_middle_2->setPosition(2587,200);
    brige_2_3 = true;
    map->addChild(brige_2_middle_2);
    brige_2_right = BrigeRight::create();
    brige_2_right->setPosition(2661,200);
    brige_2_4 = true;
    map->addChild(brige_2_right);
    
}
void GameScene::gameOver(){
        Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5, MainScene::createScene()));
}
void GameScene::addBoos(){
    boos = Sprite::create("boos.png");
    boos->setAnchorPoint(Vec2(0,0));
    boos->setPosition(7335, 0);
    map->addChild(boos);
}
void GameScene::youWin(){
    Vector<SpriteFrame*> allFrames;
    for (int i = 0; i < 2; i++) {
        char txt[100] = {};
        sprintf(txt, "boosDie%d.png", i+1);
        SpriteFrame * spriteFrame = SpriteFrame::create(txt, Rect(0,0,246,140));
        allFrames.pushBack(spriteFrame);
    }
    Animation* animation = Animation::createWithSpriteFrames(allFrames, 0.2);
    boosDieAction = boos->runAction(RepeatForever::create(Animate::create(animation)));
    boosDieTimeOut = 0;
}
