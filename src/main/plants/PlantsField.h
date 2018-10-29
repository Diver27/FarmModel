//
// Created by Ç±Ë®ÈË on 2018/10/29.
//

#ifndef FARMMODEL_PLANTSFIELD_H
#define FARMMODEL_PLANTSFIELD_H

#include <list>
#include "AbstractPlant.h"
using namespace std;

class PlantsField {
private:
    list<AbstractPlant*> farmField;
public:
    PlantsField(void){}
};


#endif //FARMMODEL_PLANTSFIELD_H
