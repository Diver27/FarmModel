//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_TESTCLASSB_H
#define FARMMODEL_TESTCLASSB_H

#include "testClassA.h"
class testClassB {
private:
    testClassA* A;
public:
    testClassB(int val){
        A=new testClassA(val);
    }
    int getVal(void){
        return A->getVal();
    }
};


#endif //FARMMODEL_TESTCLASSB_H
