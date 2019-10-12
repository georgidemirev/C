#include <iostream>
#include "Header.h"
using namespace std;

WebPage::WebPage() {
	adress = 0;
	ip = 0;
};

WebPage::WebPage(char* a,char* b) {
	adress = a;
	ip = b;
};

WebPage::~WebPage() {};

void WebPage::print() const {
	cout <<"The adress of the Web page is: "<< adress << endl <<"The IP adress of the Web page is: "<< ip << endl;
};

void WebPage::read() {
	char* adress = new char[MAX];
	cin >> adress;
	this->adress = adress;

	char* ip = new char[MAX];
	cin >> ip;
	this->ip = ip;
};


Browser::Browser() {
	count = -1;
}

Browser::Browser(WebPage page, int count) {
	webpages[0]=page;
	this->count = count;
};

Browser::Browser(const Browser& copy){};

Browser::~Browser() {};

void Browser::add() {
	WebPage a;
	a.read();
	webpages[++count] = a;
};

void Browser::print(int count) const {
	for (int i = 0; i <= count-1; i++)
	{
		cout << "Webpage "<<i+1<<endl;
		webpages[i].print();
	}
};

Browser Browser::operator+=(const Browser b) {
	WebPage a;
	a.read();
	webpages[++count] = a;
	return b;
};

void Browser::out(int) {

};