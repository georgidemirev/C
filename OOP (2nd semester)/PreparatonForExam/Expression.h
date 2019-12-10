#pragma once
#include "Printable.h"
#include "Cloneable.h"

template<class T>
class Expression:public Printable<T>, public Cloneable<T> {
public:
	virtual ~Expression() {};

	virtual T value() const = 0;

	virtual void print() const = 0;

	Expression<T>* clone()const = 0;
};

