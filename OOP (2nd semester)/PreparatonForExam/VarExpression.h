#pragma once
#include "ConstExpr.h"
#include <cstring>

template<class T>
class VarExpression:public ConstExpression<T> {
	char* name = nullptr;

	void setName(const char* name) {
		if (name == nullptr) {
			return;
		}
		//if(this->name == name) ne raboti  zashtoto moje da hvane name ot 2riq element

		delete[]  this->name;
		int len = strlen(name)+1;

		this->name == new char[len];
		strcpy_s(this->name, len, name);
	}
public:
	VarExpression(const char* name, const T& val):ConstExpression<T>(val) {
		setName(name);
	};

	VarExpression(const VarExpression<T>& p) {
		*this = p;
	};

	~VarExpression() { delete this->name; };

	VarExpression& operator=(const  VarExpression<T>& p) {
		if(this == *p)return *this;
		ConstExpression<T>::operator=(p);
		setName(p.getName());
		return *this;
	}

	void print() const {
		std::cout << getName();
	}

	ConstExpression<T>* clone() const {
		return new VarExpression(getName(), value());
	}

	const char* getName(){return this->name}

	


};