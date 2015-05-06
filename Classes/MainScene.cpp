//
//  MainScene.cpp
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#include <stdio.h>

#include "MainScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg = Sprite::create("MainBG.jpg");
    bg->setAnchorPoint(Vec2(0,0));
    this->addChild(bg);
    //add label
    label = LabelTTF::create("Hello", "Arial", 24);
    label->setAnchorPoint(Vec2(0, 0));
    label->setPosition(Vec2(10, 450));
    this->addChild(label);
    //add Listener for keyboard
    ListenKeyboardEvent();

    return true;
}
void MainScene::ListenKeyboardEvent(){
    this->_eventDispatcher->removeAllEventListeners();
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MainScene::onKeyPressedOwn, this);
    listener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleasedOwn, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void MainScene::onKeyPressedOwn(EventKeyboard::KeyCode code, Event* event){
    char txt[100] = {};
    sprintf(txt, "key %d pressed", int(code));
    label->setString(txt);
    //Enter Pressed
    if (int(code) == 35) {
//        Director::getInstance()->replaceScene(GameScene::createScene());
        Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5, GameScene::createScene()));
    }
}
void MainScene::onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event){
}

