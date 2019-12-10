#pragma once
#include "Currency.h"

class Observer {

public:

	virtual void update(const Currency& curr) = 0;

	virtual Observer* clone() const = 0;
};