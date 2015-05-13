//
//  MapData.cpp
//  ContraGame
//
//  Created by Heaven on 5/12/15.
//
//

#include "MapData.h"
float* MapData::getHeight(float x){
    float* attr = new float[3];
    attr[0] = 40;
    attr[1] = 40;
    attr[2] = 40;
    int xCol = (int) x/74;
    CCLOG("xPosition = %f", x);
    CCLOG("xPositionCol = %d", xCol);
    if (xCol == 64) {
        attr[0] = 250;
        attr[1] = 200;
        attr[2] = 90;
    }else if(xCol == 44 or xCol == 58 or xCol == 78){
        attr[0] = 250;
        attr[1] = 200;
        attr[2] = 40;
    }else if(xCol == 45 or xCol == 46 or xCol == 57){
        attr[0] = 250;
        attr[1] = 40;
    }else if(xCol == 43){
        attr[0] = 250;
        attr[1] = 200;
    }else if(xCol == 50 or xCol == 51 or xCol == 52 or xCol == 53 or xCol == 68){
        attr[0] = 250;
        attr[1] = 140;
    }else if(xCol == 54 or xCol == 55 or xCol == 56){
        attr[0] = 250;
        attr[1] = 140;
        attr[2] = 40;
    }else if(xCol == 47 or xCol == 48 or xCol == 66 or xCol == 79){
        attr[0] = 250;
        attr[1] = 115;
        attr[2] = 40;
    }else if(xCol == 49 or xCol == 65 or xCol == 67){
        attr[0] = 250;
    }else if(
             (xCol>0 and xCol<5)or
             (xCol>14 and xCol<19)or
             (xCol>27 and xCol<33)or
             (xCol>36 and xCol<43)or
             (xCol == 12 or xCol == 23 or xCol == 62 or xCol == 71 or xCol == 77 or xCol == 81)){
        attr[0] = 200;
    }else if(xCol == 5 or xCol == 6 or xCol == 7 or xCol == 13 or xCol == 14 or xCol == 70 or xCol == 82){
        attr[0] = 200;
        attr[1] = 140;
    }else if(xCol == 20 or xCol == 95 or xCol == 96){
        attr[0] = 200;
        attr[1] = 115;
        attr[2] = 40;
    }else if(xCol == 21 or xCol == 22){
        attr[0] = 200;
        attr[1] = 115;
    }else if(xCol == 8 or xCol == 11 or xCol == 60 or xCol == 61 or xCol == 63){
        attr[0] = 200;
        attr[1] = 90;
    }else if(xCol == 9 or xCol == 10 or xCol == 19 or xCol == 59 or xCol == 94){
        attr[0] = 200;
        attr[1] = 40;
    }else if(xCol == 74){
        attr[0] = 140;
        attr[1] = 90;
    }else if(xCol == 73 or xCol == 85 or xCol == 86 or xCol == 97){
        attr[0] = 140;
        attr[1] = 40;
    }else if(xCol == 69 or xCol == 83 or xCol == 84 or xCol == 92 or xCol == 93){
        attr[0] = 140;
    }else if(xCol == 75 or xCol == 76 or xCol == 89 or xCol == 90){
        attr[0] = 90;
    }else if(xCol == 98){
        attr[0] = 90;
        attr[1] = 40;
    }else if(xCol == 87 or xCol == 99){
        attr[0] = 40;
    }else
        CCLOG("Warring:%d", xCol);
    return attr;
//    return dataList[(int) x/74];
}
MapData::MapData(){
    for (int i = 0; i<22; i++) {
//        Vector<float*> data;
//        dataList.pushBack(data);
        float *data = new float[3];
    }
}
