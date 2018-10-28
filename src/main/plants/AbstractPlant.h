//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_ABSTRACTPLANT_H
#define FARMMODEL_ABSTRACTPLANT_H


class AbstractPlant {
private:
    bool matureMeter;
    int size;
public:
    AbstractPlant(int _size):size(_size),matureMeter(false){}
    void setMature(bool val){
        matureMeter=val;
    }
    bool isMature(void){
        return matureMeter;
    }
    virtual void harvest()=0;
};


#endif //FARMMODEL_ABSTRACTPLANT_H
