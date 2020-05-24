#include "stdafx.h"
#include "User.h"
#include "Product.h"
#include "Store.h"
#include <iostream>
#include <algorithm>

using namespace std;

Store::Store(string const name) :name(name) {}

Store::~Store() {
};

Store::Store(const Store &other) : name(other.getName()) {
	vector<User*> vectorUsers(users);
	this->users = vectorUsers;
	vector<Product*> vectorProducts(products);
	this->products = vectorProducts;
};

Store& Store::operator=(const Store& other)
{
	this->name = other.getName();
	vector<User*> vectorUsers(other.getUsers());
	this->users = vectorUsers;
	vector<Product*> vectorProducts(other.getProducts());
	this->products = vectorProducts;
	return *this;
};

void Store::addProduct(Product* const product)
{
	Product *newProduct = product;
	products.push_back(newProduct);
}

void Store::removeProduct(string const name)
{
	Product *foundProduct = findProductByName(name);

	if (foundProduct == NULL) return;

	products.erase(remove(products.begin(), products.end(), foundProduct), products.end());

	// deleting only when the product is removed from the store,
	// not from the shopping carts of different users
	delete foundProduct;
}

User* Store::findUserByUsername(string const username)
{
	for (int i = 0; i < users.size(); i++) {
		if ((*this->users[i]).getUsername() == username)
		{
			return users[i];
		}
	}
	return NULL; 
}

Product* Store::findProductByName(string const name)
{
	for (int i = 0; i < products.size(); i++) {
		if ((*products[i]).getName() == name)
		{
			return products[i];
		}
	}
	return NULL;
}

bool Store::doesUserExistByUsername(string const username) 
{
	for (int i = 0; i < users.size(); i++) {
		if ((*this->users[i]).getUsername() == username)
		{
			return true;
		}
	}
	return false;
}

bool Store::doesUserExistById(int id)
{
	for (int i = 0; i < users.size(); i++) {
		if ((*this->users[i]).getId() == id)
		{
			return true;
		}
	}
	return false;
}

bool Store::doesProductExistByName(string const name) 
{
	for (int i = 0; i < users.size(); i++) {
		if ((*this->products[i]).getName() == name)
		{
			return true;
		}
	}
	return false;
}

bool Store::hasEnoughMoney(string const username, double const money)
{
	User *user = findUserByUsername(username);

	if ((*user).getMoneyInWallet() >= money) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Store::registerUser(string const username, string const password, int const id)
{
	if (doesUserExistById(id) || doesUserExistByUsername(username))
	{
		cout << endl << "user with that id or that username already exists" << endl;
	}

	User *newUser = new User(username, password, id);

	users.push_back(newUser);
}

void Store::removeUser(string const username)
{
	User *foundUser = findUserByUsername(username);

	if (foundUser == NULL) return;

	users.erase(remove(users.begin(), users.end(), foundUser), users.end());

	delete foundUser;
}

void Store::addProductToCart(string const username, string const product, int const quantity)
{
	User *user = findUserByUsername(username);

	Product *productFromStore = findProductByName(product);

	if (productFromStore == NULL || user == NULL) return;

	if ((*productFromStore).getQuantity() < quantity)
	{
		cout << "Can not add more than available" << endl;
		return;
	}

	Product *productForCart = new Product();

	*productForCart = *productFromStore;

	(*productForCart).setQuantity(quantity);

	ShoppingCart *cart = (*user).getShoppingCart();

	(*(*user).getShoppingCart()).addProduct(productForCart);

	//remove the added quantity from the store
	(*productFromStore).setQuantity((*productFromStore).getQuantity() - quantity);
}

void Store::removeProductFromCart(string const username, string const product)
{
	User *user = findUserByUsername(username);

	Product *productFromStore = findProductByName(product);

	if (user == NULL || productFromStore == NULL)
	{
		cout << "invalid username or product given" << endl;
		return;
	}

	int quantity = (*(*(*user).getShoppingCart()).findProductByName(product)).getQuantity();

	(*(*user).getShoppingCart()).removeProduct(product);

	(*productFromStore).setQuantity((*productFromStore).getQuantity() + quantity);
}

void Store::printCart(string const username)
{
	User *user = findUserByUsername(username);

	if (user == NULL)
	{
		cout << "invalid username given" << endl;
		return;
	}

	(*(*user).getShoppingCart()).printAllProducts();
}

void Store::buyEverythingFromCart(string const username)
{
	User *user = findUserByUsername(username);

	double cartPrice = (*(*user).getShoppingCart()).getCartPrice();

	if (hasEnoughMoney((*user).getUsername(), cartPrice))
	{
		double availableMoney = (*(*user).getWallet()).getMoney();
		(*(*user).getWallet()).setMoney(availableMoney - cartPrice);
		(*(*user).getShoppingCart()).clearShoppingCart();
	}
}


void Store::printAllProducts() const
{
	for (int i = 0; i < products.size(); i++)
	{
		(*products[i]).print();
		cout << endl;
	}
}

void Store::printProductsByCategory(string const category) const
{
	for (int i = 0; i < products.size(); i++)
	{
		if ((*products[i]).getCategory() == category)
		{
			(*products[i]).print();
			cout << endl;
		}
	}
}

void Store::printProductsByPrice(double const price) const
{
	for (int i = 0; i < products.size(); i++)
	{
		if ((*products[i]).getPrice() == price)
		{
			(*products[i]).print();
			cout << endl;
		}
	}
}

void Store::printProductsByName(string const name) const
{
	for (int i = 0; i < products.size(); i++)
	{
		if ((*products[i]).getName() == name)
		{
			(*products[i]).print();
			cout << endl;
		}
	}
}

string Store::getName() const
{
	return this->name;
}

vector<User*> Store::getUsers() const
{
	return this->users;
}

vector<Product*> Store::getProducts() const
{
	return this->products;
}
