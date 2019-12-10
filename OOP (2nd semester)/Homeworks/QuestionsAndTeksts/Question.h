#pragma once


class Question{
public:
	~Question() {};

	virtual void ask() = 0 ;

	virtual double grade() = 0;

	virtual Question* clone() const = 0;
};