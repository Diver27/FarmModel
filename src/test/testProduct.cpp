#include <iostream>
#include "productFactory.h"


int main()
{
	ProductFactory myFactory;

	Product* myGoods1 = myFactory.productGoods(1);
	
	myGoods1->SellProduct();

	Product* myGoods2 = myFactory.productGoods(2);

	myGoods2->SellProduct();

	system("pause");
	return 0;
}