#ifndef MARKET
#define MARKET

#include <iostream>
#include <string>

//市场类
class Market
{
public:
	virtual void sellPrice(int n) = 0;
};

//市场用proxy Pattern实现，并且为Singleton
class RealMarket : public Market
{
public:
	static RealMarket* Instance()
	{
		return myMarket;
	}
	void sellPrice(int n)
	{
		std::cout << "产品市场价格为 "<<price[n-1] << std::endl;
	}
private:
	RealMarket()
	{
		for (int i = 0; i < 4; ++i)
			price[i] = 100 * (i + 1);
	}
	RealMarket(const RealMarket&) { }

	RealMarket& operator=(const RealMarket&) { }

private:
	static RealMarket* myMarket;
	int price[4];
};

//建立唯一市场，为Singleton Pattern
RealMarket* RealMarket::myMarket = new RealMarket();

//代理商
class ProxyBuyer : public Market 
{
public:
	void sellPrice(int n) 
	{
		RealMarket* market = RealMarket::Instance();
		market->sellPrice(n);
	}
	ProxyBuyer() {};
private:
	
};
#endif 

