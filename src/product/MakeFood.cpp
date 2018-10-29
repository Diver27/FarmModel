#include "ProductFramework.h"
using namespace std;

class food :public Product
{
public:
	food(char* fn) :Product(fn) { };
	void SellProduct() { cout << "SellProduct" << endl; }
	void ShowProduct() { cout << "food" << endl; }
};
class OurFactory :public Factory
{
public:
	OurFactory() { cout << "OurFactory" << endl; }
	Product* CreatProduct(char* fn)
	{
		return new food(fn);
	}

};
int main()
{
	OurFactory f;
	char milk[20] = "milk";
	char flour[20] = "flour";
	f.NewProduct(milk);
	f.NewProduct(flour);
	f.ReportProduct();
	cin.get();
}
