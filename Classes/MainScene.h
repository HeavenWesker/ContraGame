//
//  MainScene.h
//  ContraGame
//
//  Created by Heaven on 5/6/15.
//
//

#ifndef ContraGame_MainScene_h
#define ContraGame_MainScene_h
using namespace cocos2d;
class MainScene : public Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    LabelTTF* label;
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    void ListenKeyboardEvent();
    void onKeyPressedOwn(EventKeyboard::KeyCode code, Event* event);
    void onKeyReleasedOwn(EventKeyboard::KeyCode code, Event* event);
};


#endif
