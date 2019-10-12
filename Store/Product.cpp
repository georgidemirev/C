#include "Product.h"

Product::Product()
{
	sku = 0;
	count = 0;
	price = 0;
	brand = nullptr; 
	model = nullptr; 
}

Product::Product(int sku, char * model, char * brand, double price, int count):sku(0),count(0),price(0),brand(nullptr),model(nullptr)
{
	if (model == nullptr)model = "";
	if (brand == nullptr)brand = "";
	this->sku = sku;
	this->count = count;
	this->price = price;
	int lenB = strlen(brand) + 1;
	int lenM = strlen(model) + 1;
	delete[] this->brand;
	this->brand = new char[lenB];
	strcpy_s(this->brand, lenB, brand);
	delete[] this->model;
	this->model = new char[lenM];
	strcpy_s(this->model, lenM, model);
}

Product & Product::operator=(const Product & copy)
{
	if (this != &copy)
	{
		int lenB = strlen(copy.brand) + 1;
		int lenM = strlen(copy.model) + 1;
		delete[] this->brand;
		this->brand = new char[lenB];
		strcpy_s(this->brand, lenB, copy.brand);
		delete[] this->model;
		this->model = new char[lenM];
		strcpy_s(this->model, lenM, copy.model);
		this->sku = copy.sku;
		this->count = copy.count;
		this->price = copy.price;
		
	}return *this;
}

Product::~Product()
{
	delete[] brand;
	delete[] model;
}

void Product::printP(int i) const
{
	cout << endl << "Product "<<i<< ": " << endl;
	//cout << "SKU: " << sku << endl;
	cout << "Brand: " << brand << endl;
	cout << "Model: " << model << endl;
	cout << "Price: " << price  << endl;
	cout << "Count: " << count  << endl;
}
