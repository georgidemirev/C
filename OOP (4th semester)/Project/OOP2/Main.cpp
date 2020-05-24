// OOP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Store.h"
#include "Monitor.h"
#include "Laptop.h"
#include "Fridge.h"
#include <algorithm>

using namespace std;

int main()
{
	cout << "----------MyStore----------------" << endl;
	//Create a store
	Store store("MyStore");
	
	//Add users in the store (register user)
	cout << "->Number of users before registering: " << store.getUsers().size() << endl;
	store.registerUser("username1", "password1", 1);
	store.registerUser("username2", "password2", 2);
	store.registerUser("username3", "password3", 3);

	cout << "->Number of users in the store after registering: " << store.getUsers().size() << endl;
	
	cout << "->Users in the store: " << endl;
	cout << (*store.getUsers().at(0)).getUsername() << endl;
	cout << (*store.getUsers().at(1)).getUsername() << endl;
	cout << (*store.getUsers().at(2)).getUsername() << endl;

	//Remove user
	cout << endl << "-removing user with username1" << endl;
	store.removeUser("username1");

	cout << "->Number of users in the store: " << store.getUsers().size() << endl;

	cout << "->Users in the store: " << endl;
	cout << (*store.getUsers().at(0)).getUsername() << endl;
	cout << (*store.getUsers().at(1)).getUsername() << endl;

	//Add products in the store
	Product *product1 = new Product("product1", "category1", 10, 22.50);
	Laptop *laptop1 = new Laptop("laptop1", "category1", 20, 33.50, 50, "gpu1", "cpu1");
	Laptop *laptop2 = new Laptop("laptop2", "category1", 20, 33.50, 50, "gpu1", "cpu1");
	Monitor *monitor1 = new Monitor("monitor1", "category1", 30, 44.50, 60, "1080x720");
	Fridge *fridge1 = new Fridge("fridge1", "category2", 40, 55.50, 180, 2000);

	cout << "->Number of products in the store: " << store.getProducts().size() << endl;
	cout << "->Adding 5 products in the store" << endl;

	store.addProduct(product1);
	store.addProduct(laptop1);
	store.addProduct(laptop2);
	store.addProduct(monitor1);
	store.addProduct(fridge1);
	cout << endl << "->Number of products in the store: " << store.getProducts().size() << endl;
	store.printAllProducts();

	//Remove product from the store
	store.removeProduct("laptop2");
	cout << endl << "->Remove laptop2 from the store" << endl;
	cout << "->Number of products in the store: " << store.getProducts().size() << endl;
	store.printAllProducts();
	cout << endl;

	//Print all products from category1
	cout << "->Print all products from category1" << endl;
	store.printProductsByCategory("category1"); 

	//Add money to the wallets of the users
	cout << endl << "->Show the money of the users" << endl;
	cout << "username2: " << (*store.getUsers().at(0)).getMoneyInWallet() << endl;
	cout << "username3: " << (*store.getUsers().at(1)).getMoneyInWallet() << endl;

	cout << "->Adding money to the wallets" << endl;
	(*(*store.getUsers().at(0)).getWallet()).setMoney(1000);
	(*(*store.getUsers().at(1)).getWallet()).setMoney(2000);

	cout << "->Show the money of the users again" << endl;
	cout << "username2: " << (*(*store.getUsers().at(0)).getWallet()).getMoney() << endl;
	cout << "username3: " << (*store.getUsers().at(1)).getMoneyInWallet() << endl;

	//Add products in the shopping cart of the first user
	cout << endl << "->Add products in the shopping cart of the first user" << endl;
	store.addProductToCart("username2", "laptop1", 10);
	store.addProductToCart("username2", "monitor1", 10);
	store.addProductToCart("username2", "fridge1", 10);

	cout << endl << "->Show the poducts in the cart for user with username2" << endl;
	store.printCart("username2");

	cout << endl << "->Show again the products from the store" << endl;
	store.printAllProducts();

	cout << endl << "->Try to add more than available in the store into the shopping cart of username2:" << endl;
	store.addProductToCart("username2", "laptop1", 20);

	//Remove the laptop from the cart of the user
	cout << endl << "->Remove the laptop from the cart of the user" << endl;
	store.removeProductFromCart("username2", "laptop1");

	cout << endl << "->Show the poducts in the cart for user with username2" << endl;
	store.printCart("username2");

	cout << endl << "->Show the poducts in the store" << endl;
	store.printAllProducts();

	//Pay for the cart
	cout << endl << "->Show the money of username2" << endl;
	cout << (*store.getUsers().at(0)).getMoneyInWallet() << endl;

	cout << endl << "->Pay for the cart for username2" << endl;
	store.buyEverythingFromCart("username2");

	cout << endl << "->Show the money of username2" << endl;
	cout << (*store.getUsers().at(0)).getMoneyInWallet() << endl;

	cout << endl << "->Show the poducts in the cart for user with username2:(shoud be empty)" << endl;
	store.printCart("username2");

	//Add one more product in the cart and show it
	cout << endl << "->Add one more product in the cart and show it" << endl;
	store.addProductToCart("username2", "laptop1", 10);

	cout << endl << "->Show the poducts in the cart for user with username2" << endl;
	store.printCart("username2");

	cout << endl << endl << "There is more functionality, but this is the most important shown above" << endl;
	cout << "____________________________________________________" << endl;

	return 0;
}