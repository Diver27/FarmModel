#ifndef FLY_WEIGHT
#define FLY_WEIGHT

#include <iostream>
#include <string>
#include <map>

//产品信息，用 flyweight patern实现
class trademarkFlyweight
{

public:
	trademarkFlyweight(std::string strName) :m_trademark(strName) {}
	virtual void setFarm(std::string strFarm) = 0;
	virtual void setOrginPlace(std::string strPlace) = 0;
	virtual void setGoodsName(std::string strGoods) = 0;
	std::string GetName()
	{
		return m_trademark;
	}

private:
	std::string m_trademark;
};


class concreteTrademarkFlyweight : public trademarkFlyweight
{

public:
	concreteTrademarkFlyweight(std::string trademark) :trademarkFlyweight(trademark)
	{
		std::cout << GetName() << std::endl;
	}
	void setFarm(std::string strFarm)
	{
		m_farmName = strFarm;
		std::cout << m_farmName << std::endl;
	}
	void setOrginPlace(std::string strPlace)
	{
		m_orginPlace = strPlace;
		std::cout << m_orginPlace << std::endl;
	}
	void setGoodsName(std::string strGoods)
	{
		m_goodsName = strGoods;
		std::cout << m_goodsName << std::endl;
	}

private:
	std::string m_farmName;
	std::string m_orginPlace;
	std::string m_goodsName;
};

class FlyweightFactory
{
public:
	FlyweightFactory() {}
	~FlyweightFactory()
	{
		for (std::map<std::string, trademarkFlyweight*>::iterator it = m_mapMark.begin(); it != m_mapMark.end(); it++)
		{
			delete it->second;
		}
	}

	trademarkFlyweight* GetMark(std::string strName)
	{
		std::map<std::string, trademarkFlyweight*>::iterator it = m_mapMark.find(strName);
		if (it != m_mapMark.end())
		{
			if (it->second->GetName() != strName)
			{
				return NULL;
			}
			return it->second;
		}
		trademarkFlyweight* tmfw = new concreteTrademarkFlyweight(strName);
		m_mapMark[strName] = tmfw;
		return m_mapMark[strName];
	}

private:
	std::map<std::string, trademarkFlyweight*> m_mapMark;
};


FlyweightFactory* creatFlyweightFactory()
{
	FlyweightFactory* fwFactory = new FlyweightFactory();
	return fwFactory;
}

trademarkFlyweight* creatTrademark(FlyweightFactory* factory, int n)
{
	trademarkFlyweight * tradeMark = NULL;
	switch (n)
	{
	case 1:
		tradeMark = factory->GetMark("Superior");
		tradeMark->setFarm("Tongji farm");
		tradeMark->setGoodsName("Ham");
		tradeMark->setOrginPlace("Jiading");
		return tradeMark;
		break;
	case 2:
		tradeMark = factory->GetMark("Lovely");
		tradeMark->setFarm("Jiaotong Farm");
		tradeMark->setGoodsName("Fresh Milk");
		tradeMark->setOrginPlace("Chongming");
		return tradeMark;
		break;
	case 3:
		tradeMark = factory->GetMark("Windy");
		tradeMark->setFarm("Fudan Farm");
		tradeMark->setGoodsName("Yogurt");
		tradeMark->setOrginPlace("Fengxian");
		return tradeMark;
		break;
	case 4:
		tradeMark = factory->GetMark("BJR's");
		tradeMark->setFarm("Caijin farm");
		tradeMark->setGoodsName("Blanket");
		tradeMark->setOrginPlace("Baoshan");
		return tradeMark;
		break;
	default:
		std::cout << "Type an option(1~4)" << std::endl;
		return NULL;
	}
}

#endif 