//
// Created by Ç±Ë®ÈË on 2018/10/29.
//

#ifndef FARMMODEL_PLANTACTIONSTRATEGY_H
#define FARMMODEL_PLANTACTIONSTRATEGY_H

#include <iostream>
using namespace std;

/**
 * Strategy template. Choose different action to do for a plant field.
 */
class PlantActionStrategy {
public:
    virtual void action(void)=0;
    PlantActionStrategy(void){}
};

/**
 * Burn the plants to clean the field
 */
class burnDown:public PlantActionStrategy{
public:
    void action(void){
        cout<<"The field is burnt down"<<endl;
    }
    burnDown(void){}
};

/**
 * Spray water to the field
 */
class sprayWater:public PlantActionStrategy{
public:
    void action(void){
        cout<<"the field is sprayed water"<<endl;
    }
    sprayWater(void){}
};

#endif //FARMMODEL_PLANTACTIONSTRATEGY_H
