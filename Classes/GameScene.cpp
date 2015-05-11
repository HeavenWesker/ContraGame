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
#include "Bullet.h"

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
    
    auto bg = Sprite::create("bg.jpg");
    bg->setAnchorPoint(Vec2(0,0));
    this->addChild(bg);
    //add hero
    hero = Hero::create();
    hero->setPosition(120, 200);
    this->addChild(hero);
    
    auto bullet = Bullet::create();
    bullet->setPosition(150, 200);
    this->addChild(bullet);

//    this->schedule(schedule_selector(GameScene::update), 0.01);
    isFiring = false;
    ListenKeyboardEvent();
    scheduleUpdate();

    return true;
}
void GameScene::update(float dt){
//    CCLOG("GameScene::update %f", dt);
    count ++;
    if (isFiring) {
        if (count % 10 == 0) {
            fire();
        }
    }
    hero->update(dt);
    moveBullets(dt);
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
    bullet->setPositionX(hero->getPositionX()+(hero->directionRight?20:-20));
    bullet->setPositionY(hero->getPositionY()+(hero->isDown?13:36));
    addChild(bullet);
    bullets.pushBack(bullet);
}
void GameScene::moveBullets(float dt){
    for (int i = 0; i < bullets.size(); i++) {
        auto bullet = bullets.at(i);
        bullet->update(dt);
        if (outScreen(bullet)) {
            bullet->removeFromParent();
            bullets.eraseObject(bullet);
            i--;
        }
    }
}
bool GameScene::outScreen(Node* node){
    if (node->getPositionX()>600 || node->getPositionX()<-20 ||
        node->getPositionY()>600 || node->getPositionY()<-20) {
        return true;
    }
    return false;
}