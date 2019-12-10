#pragma once
#include <iostream>
#include <string>
#include "Question.h"

class YesNoQ: public Question {
private:
	
	char* question = nullptr;
	double points;
	std::string answer;

	const char* getQuestion()const { return this->question; }
	const std::string getAnswer() const { return this->answer; }
	const double getPoints() const { return this->points; }

	void setQuestion(const char* p) {
		if (p == nullptr)return;
		delete[] question;
		question = new char[strlen(p) + 1];
		strcpy_s(question, strlen(p) + 1, p);
	}
	void setAnswer(const std::string p) { answer = p; }
	void setPoints(const double p) { points = p; }
	
public:
	YesNoQ() :question("DefQuestion"), answer("DefAnswer"), points(0) {};
	YesNoQ(char* q, std::string a, double p) :question(q), answer(a), points(p) {};
	YesNoQ(const YesNoQ& p) {
		setQuestion(p.getQuestion());
		setAnswer(p.getAnswer());
		setPoints(p.getPoints());
	};
	YesNoQ& operator=(const YesNoQ& p) {
		setQuestion(p.getQuestion());
		setAnswer(p.getAnswer());
		setPoints(p.getPoints());
	}
	~YesNoQ() { delete[] question; }

	void ask() override {
		std::cout << getQuestion() << std::endl;
		std::string in;
		std::getline(std::cin, in);

		if (in != getAnswer())
		{
			setPoints(0);
		}
	}

	double grade() override{
		return getPoints();
	}

	Question* clone() const override { return new YesNoQ(*this); }

};