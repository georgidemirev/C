#pragma once

template<class T>
class Cloneable {
public:
	virtual Cloneable* clone() const = 0;

	virtual~Cloneable() {};
};


