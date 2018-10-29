//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_WHEAT_H
#define FARMMODEL_WHEAT_H

#include "AbstractPlant.h"
#include <iostream>
using namespace std;

/**
 * Definition for class Wheat
 */
class Wheat:public AbstractPlant {
public:
    Wheat(int _size):AbstractPlant(_size){}

    /**
     * The wheat's specific collect procedure
     */
    void collect(){
        mowDown();
        packUp();
        transport();
        cout<<"Wheat has been harvested"<<endl;
    }
private:
    void mowDown(void){
        cout<<"The wheat field is mowed down."<<endl;
    }
    void packUp(void){
        cout<<"The wheat is packed up as wheat rolls"<<endl;
    }
    void transport(void){
        cout<<"The wheat rolls are collected by trucks."<<endl;
    }
};


#endif //FARMMODEL_WHEAT_H
