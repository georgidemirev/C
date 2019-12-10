#pragma once
#ifndef HEADER_H
#define HEADER_H

class Rational {
private:
	int numer, denom;
	int gcd(int, int);

public:
	// ������������
	Rational();
	Rational(int, int);
	// ������� �� ������
	int getNumerator() const;
	int getDenominator() const;
	void print() const;
	// �������
	void read();
};

Rational add(Rational, Rational);
Rational subtract(Rational, Rational);
Rational multiply(Rational, Rational);
Rational divide(Rational, Rational);

#endif