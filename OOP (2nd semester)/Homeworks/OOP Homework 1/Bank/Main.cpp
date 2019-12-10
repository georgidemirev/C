#include "stdafx.h"
#include "CentralBank.h"

int main()
{

	Currency curr1("USD", 1.5), curr2("BGN", 2), curr3("EUR", 2.5);

	ConcreteObserver* c1 = new ConcreteObserver("Georgi");
	ConcreteObserver* c2 = new ConcreteObserver("Stoykov");

	CentralBank cb;

	cb.regitser(c1);
	cb.regitser(c2);

	CentralBank cb2(cb);

	cb2.addCurrency(curr1);
	cb2.addCurrency(curr2);
	cb2.deleteCurrency("USD");

	cb2.setRate("BGN", 5);


    return 0;
}
