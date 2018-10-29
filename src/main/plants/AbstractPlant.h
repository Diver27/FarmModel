//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_ABSTRACTPLANT_H
#define FARMMODEL_ABSTRACTPLANT_H

#include <iostream>
#include "PlantActionStrategy.h"
using namespace std;

/**
 * Abstract class for all kinds of plants
 */
class AbstractPlant {
private:
    bool matureMeter;
    int size;
    Context* context;
public:
    AbstractPlant(int _size):size(_size),matureMeter(false),context(NULL){}

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

    void doAction(int choice){
        context=new Context(choice);
        context->doAction();
        delete context;
    }

    /**
     * Template method. Collect the plant
     */
    virtual void collect()=0;
};


#endif //FARMMODEL_ABSTRACTPLANT_H
