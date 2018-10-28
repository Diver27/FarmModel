//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_WHEAT_H
#define FARMMODEL_WHEAT_H

#include "AbstractPlant.h"
#include <iostream>
using namespace std;

class Wheat:public AbstractPlant {
public:
    Wheat(int _size):AbstractPlant(_size){}
    void harvest(){
        mowDown();
        packUp();
        collect();
        cout<<"Wheat harvesting process finished."<<endl;
    }
private:
    void mowDown(void){
        cout<<"The wheat field is mowed down."<<endl;
    }
    void packUp(void){
        cout<<"The wheat is packed up as wheat rolls"<<endl;
    }
    void collect(void){
        cout<<"The wheat rolls are collected by trucks."<<endl;
    }
};


#endif //FARMMODEL_WHEAT_H
