#pragma once
#include "Expression.h"

template<class T>
class Expr {

	Expression<T>* obj = nullptr;

public:
	Expr() {};
	Expr(const Expression<T>& expression) {
		setExpression(expression);
	}
	Expr(const Expr<T>& expr) {
		setEpression(expr.getExpression());
	}
	Expr& operator=(const Expr<T>& o) {
		setEpression(o.getExpression());
		return *this;
	}
	~Expr() {delete obj;}
	
	void setExpression(const Expression<T>& expression) {
		if (obj == &expression)return;
		delete obj;
		obj = expression.clone();
	}

	const Expression<T>& getExpression() const { // 2 getters 
		//Nullptr check
		return *this->obj;
	}
	Expression<T>& getExpression() {
		//Nullptr check
		return *this->obj;
	}


	const Expression<T>& operator->()const {
		return getExpression();
	}
	Expression<T>& operator->() {
		return getExpression();
	}

};