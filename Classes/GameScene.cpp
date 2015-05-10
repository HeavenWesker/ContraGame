//
//  GameScene.cpp
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#include <stdio.h>

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
    
    auto bg = Sprite::create("bg.jpg");
    bg->setAnchorPoint(Vec2(0,0));
    this->addChild(bg);
    //add hero
    hero = Hero::create();
    hero->setPosition(120, 200);
    this->addChild(hero);

//    this->schedule(schedule_selector(GameScene::update), 0.01);
    scheduleUpdate();

    return true;
}
void GameScene::update(float dt){
//    CCLOG("GameScene::update %f", dt);
    hero->update(dt);
}
