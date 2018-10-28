//
// Created by Ç±Ë®ÈË on 2018/10/28.
//
#include <iostream>
#include "../main/plants/Wheat.h"
#include "../main/plants/Cotton.h"
using namespace std;

int main(void){
    Wheat wheat(3);
    wheat.setMature(true);
    cout<<wheat.isMature()<<endl;
    wheat.harvest();
    Cotton cotton(1);
    cout<<cotton.isMature()<<endl;
    cotton.harvest();
    return 0;
}