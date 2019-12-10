#pragma once
#include <string>
#include "Observer.h"

class ConcreteObserver: public Observer {

	std::string observerName;

public:

	ConcreteObserver() :observerName("DefObserverName") {};
	ConcreteObserver(std::string name) :observerName(name) {};
	ConcreteObserver(const ConcreteObserver& p): observerName(p.getObserverName()){};
	ConcreteObserver& operator= (const ConcreteObserver& p) { setObserverName(p.getObserverName()); };
	~ConcreteObserver() {};

	const std::string getObserverName() const { return this->observerName; };
	void setObserverName(const std::string name) { this->observerName = name; };

	void update(const Currency& curr) {
		std::cout << this->observerName << ": " << curr.getName() << ": " << curr.getRate() << std::endl;
	};

	Observer* clone() const override { return new ConcreteObserver(*this); }

};