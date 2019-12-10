#pragma once
#include "YesNoQ.h"
#include "MultipleChoice.h"
#include "OpenQ.h"

class Test {
private:

	std::vector<Question*> test;
	double allPoints;

	void setTest(const std::vector<Question*>& test) {
		if (this->test != test) {
			deleteObservers();
			for (int i = 0; i < test.size(); i++) {
				this->test.push_back(test[i]->clone());
			}
		}
	}

	const std::vector<Question*>& getTest() const { return this->test; }
	
	void deleteObservers(){
		for (int i = 0; i < test.size(); i++)
		{
			delete test[i];
		}
		test.clear();
	}
public:
	Test(){};
	Test(const std::vector<Question*>& q) { setTest(q); };
	Test(const Test& p) {
		setTest(p.getTest());
	};
	Test& operator=(const Test& p) {
		setTest(p.getTest());
	}
	~Test() { deleteObservers(); };


	void addQuestion(Question* p) {
		test.push_back(p->clone());
	};

	void doTest() {
		for (int i = 0; i < test.size(); i++) {
			test[i]->ask();
			this->allPoints += test[i]->grade();
		}
	};

	double gradeTest() {
		return this->allPoints;
	};
};