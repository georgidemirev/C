#pragma once

template<class T>
class Printable {
public:
	virtual void print() const = 0;

	virtual ~Printable() {};
};

