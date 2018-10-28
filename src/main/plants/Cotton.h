//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_COTTON_H
#define FARMMODEL_COTTON_H

#include "AbstractPlant.h"
#include <iostream>
using namespace std;

/**
 * Definition for the class Cotton
 */
class Cotton:public AbstractPlant {
public:
    Cotton(int _size):AbstractPlant(_size){}

    /**
     * The cottons' specific harvest procedure
     */
    void harvest(){
        pick();
        dryInSun();
        store();
        cout<<"Cotton harvesting process finished."<<endl;
    }
private:
    void pick(void){
        cout<<"The cottons are picked and stored in bags."<<endl;
    }
    void dryInSun(void){
        cout<<"The cottons are exposed and dried in the sunlight"<<endl;
    }
    void store(void){
        cout<<"The cottons are collected and stored"<<endl;
    }
};


#endif //FARMMODEL_COTTON_H
