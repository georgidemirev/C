#pragma once
#include<iostream>
#include "Expression.h"
#include "Expr.h"

template<class T>
class OpExpression : public Expression<T> {

	Expr<T>* elements = nullptr;
	int size = 0;

	void setSize(int size) {
		this->size = size;
	}

	void setElements(int size, const Expr<T>* elements) {
		if (elements == nullptr) return;

		delete[] this->elements;

		this->elements = new Expr<T>[size];

		for (int i = 0; i < size; i++)
			this->elements[i] = elements[i];

		setSize(size);
	}

protected:

	const Expr<T>* getElements() const {
		return this->elements;
	}

	int getSize() const {
		return this->size;
	}

	virtual T aggregate() const = 0;
	virtual void op(std::ostream&) const = 0;
	virtual char ope() const = 0;

public:

	OpExpression(int size, const Expr<T>* elements) {
		setElements(size, elements);
	}

	OpExpression(const OpExpression<T>& o) {
		*this = o;
	}
	OpExpression<T>& operator=(const OpExpression<T>& o) {
		if (this == &o) return;
		setElements(getSize(), getElements());

		return *this;
	}

	T value() const {
		return aggregate();
	}

	void print() const {
		for (int i = 0; i < getSize(); i++) {
			std::cout << "(" << getElements()[i]->value() << ")";
			if (i != getSize() - 1) cout << op();
		}
		cout << endl;
	}

	~OpExpression() {
		delete[] this->elements;
	}

};