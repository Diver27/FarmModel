//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_TESTCLASSA_H
#define FARMMODEL_TESTCLASSA_H

#include <iostream>
using namespace std;

class testClassA {
private:
    int val;
    int calculate(int input){
        return input*(++input);
    };
public:
    testClassA(int value):val(value){
        cout<<"Class Created!"<<endl;
    }
    int getVal(void){
        return calculate(val);
    }
};


#endif //FARMMODEL_TESTCLASSA_H
