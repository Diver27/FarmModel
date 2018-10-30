//
// Created by Ǳˮ�� on 2018/10/28.
//

#ifndef FARMMODEL_ABSTRACTPLANT_H
#define FARMMODEL_ABSTRACTPLANT_H

#include <iostream>
#include "PlantActionStrategy.h"
#include "../visitor/Visitor.h"

using namespace std;

/**
 * Abstract class for all kinds of plants
 */
class AbstractPlant {
private:
    bool matureMeter;
    int size;
    PlantActionStrategy* strategy;
public:
    AbstractPlant(int _size):size(_size),matureMeter(false),strategy(NULL){}

    /**
     * Set if the plant is mature
     * @param val
     */
    void setMature(bool val){
        matureMeter=val;
    }

    /**
     * Get the plant's maturing status
     * @return
     */
    bool isMature(void){
        return matureMeter;
    }

    /**
     * Harvest the plant
     */
    void harvest(void){
        cout<<"Begin harvest process..."<<endl;
        cout<<"Assemble workers"<<endl;
        collect();
        cout<<"Harvest process finished"<<endl;
    }

    /**
     * Select action from Strategy and do it on this plant field
     * @param opt
     */
    void doAction(int opt){
        switch(opt){
            case 1:
                strategy=new burnDown();
                break;
            case 2:
                strategy=new sprayWater();
                break;
        }
        strategy->action();
    }

    /**
     * Template method. Collect the plant
     */
    virtual void collect()=0;

    /**
    * visitor pattern
    */
    virtual void Accept(IVisitor *visitor) = 0;
};


#endif //FARMMODEL_ABSTRACTPLANT_H
