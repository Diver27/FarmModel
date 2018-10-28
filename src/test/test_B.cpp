//
// Created by Ç±Ë®ÈË on 2018/10/28.
//
#include <iostream>
#include "../main/testClassB.h"
using namespace std;

int main(void){
    int value=5;
    testClassB B(value);
    std::cout<<B.getVal()<<endl;
}