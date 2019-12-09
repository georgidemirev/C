#include "Store.h"

Store::Store() :products(nullptr), size(0), element(-1){}

Store::~Store() {
	delete[] products;
};

void Store::resize()
{
	if (size == 0)
	{
		products = new Product[1];
		size = 1;
	}
	else
	{
		Product* newProducts = new Product[size * 2];
		for (int i = 0; i < size; i++)
		{
			newProducts[i] = products[i];
		}
		delete[] products;
		products = new Product[size * 2];
		for (int i = 0; i < size; i++)
		{
			products[i] = newProducts[i];
		}
		delete[] newProducts;
		size *= 2;
	}
}

void Store::addProduct(const Product &p)
{
	if (size == element+1)resize();
	products[++element] = p;
}

void Store::removeProduct(int p)
{
	for (int i = p - 1; i < element; i++)
	{
		products[i] = products[i + 1];
	}
	element--;

}

void Store::changeProduct(int i, const Product& p)
{
	products[i - 1] = p;
}

void Store::printStore() const
{
	if (size == 0)cout << "Trying to print an empty store!" << endl;
	for (int i = 0; i <= element; i++)
	{
		products[i].printP(i+1);
	}
}

