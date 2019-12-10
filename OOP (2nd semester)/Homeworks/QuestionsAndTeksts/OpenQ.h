#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Question.h"

class OpenQ : public Question {
private:
	
	double points;
	std::string question;
	std::string answer;
	
	const std::string getQuestion()const { return this->question; }
	const std::string getAnswer() const { return this->answer; }
	const double getPoints() const { return this->points; }

	void setQuestion(const std::string p) { this->question = p; }
	void setAnswer(const std::string p) { this->answer = p; }
	void setPoints(const double p) { this->points = p; }

public:
	OpenQ() :question("DefQuestion"), points(0) {};
	OpenQ(std::string q, double p) :question(q), points(p) {};
	OpenQ(const OpenQ& p) {
		setQuestion(p.getQuestion());
		setAnswer(p.getAnswer()); //when we copy, do we need to copy the answers too ? I think no.
		setPoints(p.getPoints());
	};
	OpenQ& operator=(const OpenQ& p) {
		setQuestion(p.getQuestion());
		setAnswer(p.getAnswer()); //when we copy, do we need to copy the answers too ? I think no.
		setPoints(p.getPoints());
	}
	~OpenQ() {};

	void ask() override {
		std::cout << getQuestion() << std::endl;
		std::string in;
		std::getline(std::cin, in);
		setAnswer(in);
	}

	double grade() override {
		if (getAnswer() == "") {
			return 0;
		}
		
		std::cout << "Evaluate the answer in percents(0 - 100)." << std::endl;
		std::cout <<"And the answer is:"<<std::endl<< getAnswer() << std::endl;
		double a;
		std::cin >> a;

		return getPoints()*a/100;
	}

	Question* clone() const override { return new OpenQ(*this); }

};