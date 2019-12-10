#pragma once
#include "OpExpression.h"

template<class T>
class SumExpression : public OpExpression<T> {
protected:

	T aggregate() const {
		T sum = T();
		for (int i = 0; i < getSize(); i++) {
			sum += getElements()[i]->value();
		}

		return sum;
	}

	void op(std::ostream& o) const override {
		o << '+';
	}

	char ope() const override { 
		return '+'; 
	}

public:

	SumExpression(int size, const Expr<T>* elements) : OpExpression<T>(size, elements) {};

	SumExpression<T>* clone() const {
		return new SumExpression<T>(getSize(), getElements());
	}
};
