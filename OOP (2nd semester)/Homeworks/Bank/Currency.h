#pragma once
#include <iostream>
#include <string>
//using namespace std;

class Currency {
private:

	std::string name;
	double rate;

public:

	Currency() :name(""), rate(0.0) {  };
	Currency(std::string name, double rate) :name(name), rate(rate) {}
	Currency(const Currency& p) {
		setName(p.getName());
		setRate(p.getRate()); { }
	};
	~Currency() {};

	void setName(std::string name) { this->name = name; }
	void setRate(double rate) { this->rate = rate; }

	const std::string getName()const { return this->name; }
	const double getRate()const { return this->rate; }
};