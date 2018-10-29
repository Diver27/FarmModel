#ifndef FARMWORK_PRODUCT
#define FARMWORK_PRODUCT

#include <iostream>
using namespace std;

class Product
{
public:
	Product(char *fn) { strncpy_s(name, fn, sizeof(name)); }
	char* GetName() { return name; }
	virtual void SellProduct() = 0;
	void SetLabel(char *fn) { strncpy_s(lable, fn, sizeof(lable)); };
	void SetPrice(int fn) { price = fn; };
	char* GetLable() { return lable; }
	int GetPrice() { return price; }
private:
	char name[20];
	char lable[50];
	int price;
};
class Factory
{
public:
	Factory() :_ProductNum(0) {};
	void NewProduct(char * name)
	{
		_product[_ProductNum] = CreatProduct(name);
		_ProductNum++;
	}
	void ReportProduct()
	{
		for (int i = 0; i < _ProductNum; i++)
			cout << " " << _product[i]->GetName() << endl;
	}
	virtual Product* CreatProduct(char*) = 0;
private:
	int _ProductNum;
	Product* _product[20];

};
#endif //FARMWORK_PRODUCT
