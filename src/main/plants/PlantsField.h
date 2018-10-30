//
// Created by 潜水人 on 2018/10/29.
//

#ifndef FARMMODEL_PLANTSFIELD_H
#define FARMMODEL_PLANTSFIELD_H
#include "AbstractPlant.h"
#include "../iterator/Iterator.h"
//#include "Wheat.h"

using namespace std;

/**
 * A field to store all plants instance
 */
class PlantsField {
private:
    Container<AbstractPlant*> * plantsField= new ConcreteContainer<AbstractPlant*>();
public:
    PlantsField(void){}

    void add(AbstractPlant*item){
        plantsField->pushItem(item);
    }
    void add(int opt){
        switch (opt){
            case 1:
                plantsField->pushItem(new Wheat(5));
                break;
            case 2:
                plantsField->pushItem(new Cotton(5));
        }
    }
    void print(void) {
        Iterator<AbstractPlant*> * iterator = plantsField->getIterator();
        int i = 1;
        for (iterator->First(); !iterator->isEnd(); iterator->Next(),i++) {
            if ((*(iterator->CurItem()))->isMature() == 1){
                cout << "第" << i << "块田已经成熟" << endl;
            }
        }
    }
};


#endif //FARMMODEL_PLANTSFIELD_H