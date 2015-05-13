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
using namespace cocos2d;
class MapData{
public:
    MapData();
//    ~MapData();
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

#endif /* defined(__ContraGame__MapData__) */
