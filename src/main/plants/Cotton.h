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
     * The cottons' specific collect procedure
     */
    void collect(){
        pick();
        dryInSun();
        store();
        cout<<"Cotton has been harvested."<<endl;
    }

    /**
    * accept visitor
    */
    virtual void Accept(IVisitor *visitor) {
        cout << "These cotton is being visited." << endl;
        visitor->Visit(this);
    }
private:
    void pick(void){
        cout<<"The cottons are picked and packed in bags."<<endl;
    }
    void dryInSun(void){
        cout<<"The cottons are exposed and dried in the sunlight"<<endl;
    }
    void store(void){
        cout<<"The cottons are collected and stored"<<endl;
    }
};


#endif //FARMMODEL_COTTON_H
