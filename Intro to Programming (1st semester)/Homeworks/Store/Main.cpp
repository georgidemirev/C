#include <iostream>
#include "Store.h"
using namespace std;

void printMenu() {
	cout << "		                ________" << endl;
	cout << "		|---------------| MENU |---------------|" << endl;
	cout << "		|To add new product, write 'A'.        |" << endl;
	cout << "		|To delete product, write 'X'.         |" << endl;
	cout << "		|To change product, write 'C'.         |" << endl;
	cout << "		|To display products, write 'D'.       |" << endl;
	cout << "		|To exit the program, write 'Q'.       |" << endl;
	cout << "		|--------------------------------------|" << endl;
	cout << "		|Please be correct with the input. :)  |" << endl;
	cout << "		|--------------------------------------|" << endl;
}

int main()
{
	Store store; // Should every count of every product has it's own SKU or should only the 
				 // different products have ???
	char a;
	int sku = 1;
	printMenu();
	do {
		cin >> a;
		switch (a) {
		case 'A': {
			sku++;
			char* brand = new char[30];// for this task we do not need more than 30 characters
			char* model = new char[30];
			double price;
			int count;
			cout << "Brand: "; cin >> brand;
			cout << "Model: "; cin >> model;
			cout << "Price: "; cin >> price;
			cout << "Count: "; cin >> count;
			store.addProduct(Product(sku, brand, model, price, count));
		}; break;
		case 'X': {
			if (store.getElement() == -1)
			{
				cout << "Empty store!" << endl;
				break;
			}
			int i;
			cout << "Which product do you want to remove(1,2,...): "; cin >> i; cout<<"Product removed." << endl;
			store.removeProduct(i);
		}; break;
		case 'C': {
			if (store.getElement() == -1)
			{
				cout << "Empty store!" << endl;
				break;
			}
			sku++;
			cout << "Which product do you want to change(1,2,...): ";
			int p; cin >> p; cout << endl;
			char* brand = new char[30];
			char* model = new char[30];
			double price;
			int count;
			cout << "Brand: "; cin >> brand;
			cout << "Model: "; cin >> model;
			cout << "Price: "; cin >> price;
			cout << "Count: "; cin >> count;
			store.changeProduct(p, Product(sku,brand,model,price,count));
		}; break;
		case 'D': {
			if (store.getElement() == -1)
			{
				cout << "Empty store!" << endl;
				break;
			}
			store.printStore();
		}; break;
		case 'Q': {
			return 0;
		};
		default: cout << "Wrong input" << endl;
		}
	} while (a != 'Q');
	
	return 0;
}

