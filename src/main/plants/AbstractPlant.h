//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_ABSTRACTPLANT_H
#define FARMMODEL_ABSTRACTPLANT_H

#include <iostream>
#include "PlantActionStrategy.h"
#include "../visitor/Visitor.h"

using namespace std;

enum PlantType
{
    cotton, wheat
};

/**
 * Abstract class for all kinds of plants
 */
class AbstractPlant {
private:
    bool matureMeter;
    int size;
    PlantActionStrategy* strategy;
    // addPrototype() saves each registered prototype here
    static AbstractPlant *_prototypes[10];
    static int _nextSlot;
protected:
    virtual PlantType returnType() = 0;
    virtual AbstractPlant *clone() = 0;
    // As each subclass of Plant is declared, it registers its prototype
    static void addPrototype(AbstractPlant *plant)
    {
        _prototypes[_nextSlot++] = plant;
    }
public:
    AbstractPlant(int _size):size(_size),matureMeter(false),strategy(NULL){}
    static AbstractPlant *findAndClone(int obj);

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

AbstractPlant *AbstractPlant::_prototypes[];
int AbstractPlant::_nextSlot;

AbstractPlant *AbstractPlant::findAndClone(int obj)
{
    PlantType type;
    if (obj == 1)
        type = wheat;
    else if (obj == 2)
        type = cotton;
    for (int i = 0; i < _nextSlot; i++)
        if (_prototypes[i]->returnType() == type)
            return _prototypes[i]->clone();
    return NULL;
}

#endif //FARMMODEL_ABSTRACTPLANT_H