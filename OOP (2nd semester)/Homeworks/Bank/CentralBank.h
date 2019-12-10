#pragma once
#include "Currency.h"
#include "ConcreteObserver.h"
#include <vector>

class CentralBank {
private:

	std::string name;
	std::vector<Currency> currList;
	std::vector<Observer*> observers;
	////////////////
	void deleteObservers();

public:

	CentralBank() :name("DefaultBank") {};
	CentralBank(const CentralBank& p) :CentralBank(p.getName(), p.getCurrency(), p.getObservers()) {};
	CentralBank(std::string name, const std::vector<Currency>& v, const std::vector<Observer*>& observers);
	CentralBank& operator=(const CentralBank& p);
	~CentralBank() {
		deleteObservers();
		currList.clear();
	};

	void setName(const std::string name) { this->name = name; };
	void setCurrency(const std::vector<Currency>& v) { this->currList = v; };// trqbva da probvam
	void setObservers(const std::vector<Observer*>& v) {
		if (this->observers != v) {
			this->deleteObservers();
			for (int i = 0; i < v.size(); i++) {
				observers.push_back(v[i]->clone());
			}
		}
	};

	const std::vector<Observer*>& getObservers() const { return this->observers; };
	const std::vector<Currency>& getCurrency() const { return this->currList; };
	const std::string getName()const { return this->name; };

	void addCurrency(const Currency& n);
	void addCurrency(const std::string name,const double rate);
	void deleteCurrency(const std::string name);
	void setRate(const std::string name, const double rate);

	void regitser(Observer* p);
	void unregister(const int index);
	void notify(const Currency& p);
};

CentralBank::CentralBank(std::string name, const std::vector<Currency>& v, const std::vector<Observer*>& observers)
{
	setName(name);
	setCurrency(v);
	setObservers(observers);
}


CentralBank & CentralBank::operator=(const CentralBank & p)
{
	setName(p.getName());
	setCurrency(p.getCurrency());
	setObservers(p.getObservers());
	return *this;
}

void CentralBank::addCurrency(const Currency& n)// tuk moje bi shte se promenq obekta
{
	currList.push_back(n);
}

void CentralBank::addCurrency(const std::string name, const double rate)
{
	Currency n(name, rate);
	currList.push_back(n);
}

void CentralBank::deleteCurrency(const std::string name)
{
	std::vector<Currency> copy = currList;
	currList.clear();
	for (int i = 0; i < copy.size(); i++)
	{
		if (copy[i].getName() == name)continue;
		currList.push_back(copy[i]);
	}
}

void CentralBank::setRate(const std::string name, const double rate)
{
	for (int i = 0; i < currList.size(); i++)
	{
		if (currList[i].getName() == name) {
			currList[i].setRate(rate);
			notify({ name,rate });
		}
		
	}
}

void CentralBank::regitser(Observer* p)
{
	observers.push_back(p->clone()); // gosho ne go pravi taka!
}

void CentralBank::unregister(const int index)
{
	if (index >= observers.size())
		return;
	else
	{
		delete observers[index];
		observers.erase(observers.begin() + index); 
	}
}

void CentralBank::notify(const Currency& p)
{
	for (int i = 0; i < getObservers().size(); i++) {
		getObservers()[i]->update(p);
	}
}

void CentralBank::deleteObservers()
{
	for (int i = 0; i < observers.size(); i++)
	{
		delete observers[i];
	}
	observers.clear();
}
