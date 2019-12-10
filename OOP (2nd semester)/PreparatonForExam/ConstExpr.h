#pragma once
#include <iostream>
#include "Expr.h"
//using namespace std;

template<class T>
class ConstExpression:public Expression<T> {

	T val;

public:

	ConstExpression(const T& value) :val(value) {}

	T value() const override {
		return this->val;
	}

	void print()const override {
		std::cout << value() << std::endl;
	}

	ConstExpression<T>* clone()const override {
		return new ConstExpression(value());
	}

};