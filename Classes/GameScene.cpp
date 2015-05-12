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
    map->setAnchorPoint(Vec2(0,0));
    this->addChild(map);
    //add hero
    hero = Hero::create();
    hero->setPosition(120, 200);
    map->addChild(hero);
    
    auto bullet = Bullet::create();
    bullet->setPosition(150, 200);
    map->addChild(bullet);
    addBombmanCount = 0;
    
//    this->schedule(schedule_selector(GameScene::update), 0.01);
    isFiring = false;
    ListenKeyboardEvent();
    scheduleUpdate();

    return true;
}
void GameScene::update(float dt){
//    CCLOG("hero position:%f", hero->getPositionX());
//    CCLOG("map position:%f", map->getPositionX());
    if (isFiring) {
        if (count % 10 == 0) {
            fire();
        }
    }
    count ++;
    if (addBombmanCount % 100 == 0) {
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
        default:
            break;
    }
}
void GameScene::onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event){
    switch (int(code)) {
        case 133://Fire
            isFiring = false;
            break;
        default:
            break;
    }
}
void GameScene::fire(){
    CCLOG("FIRE");
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
            CCLOG("bullet removed");
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
            CCLOG("bombman removed");
            i--;
        }
    }
}
void GameScene::checkHited(){
    for (int i = 0; i<bombmans.size(); i++) {
        for (int j = 0; j<bullets.size(); j++) {
            auto bombman = bombmans.at(i);
            auto bombmanRect = Rect(bombman->getPositionX(), bombman->getPositionY(), 35, 48);
            auto bullet = bullets.at(j);
            auto bulletRect = Rect(bullet->getPositionX(), bullet->getPositionY(), 10, 10);
//            if (std::abs(bombman->getPositionX()-bullet->getPositionX())<20 &&bullet->getPositionY()-bombman->getPositionY()<50) {
            if (bombmanRect.intersectsRect(bulletRect)) {
                bombmans.eraseObject(bombman);
                bombman->removeFromParent();
                bullets.eraseObject(bullet);
                bullet->removeFromParent();
                CCLOG("Hitted");
                i--;
                j--;
                break;
            }
        }
    }
}