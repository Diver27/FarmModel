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
    Container<AbstractPlant*> * farmField= new ConcreteContainer<AbstractPlant*>();
public:
    PlantsField(void){}

    void add(AbstractPlant*item){
        farmField->pushItem(item);
    }
    void add(int opt){
        farmField->pushItem(AbstractPlant::findAndClone(opt));
    }
    void print(void) {
        Iterator<AbstractPlant*> * iterator = farmField->getIterator();
        int i = 1;
        for (iterator->First(); !iterator->isEnd(); iterator->Next(),i++) {
            if ((*(iterator->CurItem()))->isMature() == 1){
                cout << "第" << i << "块田已经成熟" << endl;
            }
        }
    }
};


#endif //FARMMODEL_PLANTSFIELD_H