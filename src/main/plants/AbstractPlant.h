//
// Created by Ç±Ë®ÈË on 2018/10/28.
//

#ifndef FARMMODEL_ABSTRACTPLANT_H
#define FARMMODEL_ABSTRACTPLANT_H

/**
 * Abstract class for all kinds of plants
 */
class AbstractPlant {
private:
    bool matureMeter;
    int size;
public:
    AbstractPlant(int _size):size(_size),matureMeter(false){}

    /**
     * Set if the plant is mature
     * @param val
     */
    void setMature(bool val){
        matureMeter=val;
    }

    /**
     * Get the plant's maturing status
     * @return
     */
    bool isMature(void){
        return matureMeter;
    }

    /**
     * Template method. Harvest the plant
     */
    virtual void harvest()=0;
};


#endif //FARMMODEL_ABSTRACTPLANT_H
