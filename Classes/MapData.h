//
//  MapData.h
//  ContraGame
//
//  Created by Heaven on 5/12/15.
//
//

#ifndef __ContraGame__MapData__
#define __ContraGame__MapData__

#include <stdio.h>
//#include "GameScene.h"
using namespace cocos2d;
class MapData{
public:
    static float* getHeight(float x);
//    Vector<float*> data;
//    Vector<Vector<float*>> dataList;
//    constexpr static const float dataList[100][3]={
//        -100.0f,-100.0f,-100.0f,//0
//        200.0f,-100.0f,-100.0f,
//        200.0f,-100.0f,-100.0f,
//        200.0f,-100.0f,-100.0f,
//        200.0f,-100.0f,-100.0f,
//        200.0f,140.0f,-100,
//        200.0f,140.0f,-100,
//        200.0f,140.0f,-100,
//        200.0f,90.0f,-100,
//        200.0f,40.0f,-100,//9
//        200.0f,40.0f,-100,
//        200.0f,90.0f,-100,
//        200.0f,-100.0f,-100,
//        200.0f,140.0f,-100.f,
//    };
};
extern bool brige_1_1;
extern bool brige_1_2;
extern bool brige_1_3;
extern bool brige_1_4;
extern bool brige_2_1;
extern bool brige_2_2;
extern bool brige_2_3;
extern bool brige_2_4;

#endif /* defined(__ContraGame__MapData__) */
