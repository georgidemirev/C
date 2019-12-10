#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Question.h"

class MultipleChoice : public Question {
private:
	
	double points;
	std::string question;
	std::vector<std::string> answers;
	std::vector<std::string> correctAnswers;
	
	const std::string getQuestion()const { return this->question; }
	const std::vector<std::string>& getAnswers() const { return this->answers; }
	const std::vector<std::string>& getCorrectAnswers() const { return this->correctAnswers; }
	const double getPoints() const { return this->points; }

	void setQuestion(const std::string p) { this->question = p; }
	void setAnswers(const std::vector<std::string> p) {this->answers = p; }
	void setCorrectAnswers(const std::vector<std::string> p) { this->correctAnswers = p; }
	void setPoints(const double p) { this->points = p; }

public:
	MultipleChoice() :question("DefQuestion"), points(0) {};
	MultipleChoice(std::string q, double p, std::vector<std::string> a, std::vector<std::string> v) :question(q), answers(a), points(p),correctAnswers(v) {};
	MultipleChoice(const MultipleChoice& p) {
		setQuestion(p.getQuestion());
		setAnswers(p.getAnswers());
		setPoints(p.getPoints());
		setCorrectAnswers(p.getCorrectAnswers());
	};
	MultipleChoice& operator=(const MultipleChoice& p) {
		setQuestion(p.getQuestion());
		setAnswers(p.getAnswers());
		setPoints(p.getPoints());
		setCorrectAnswers(p.getCorrectAnswers());
	}
	~MultipleChoice() { answers.clear(); correctAnswers.clear(); };

	
	void ask() override {
		
		double finalpoints=0;

		for (int i = 0; i < getCorrectAnswers().size(); i++) {
			std::cout << getQuestion() << std::endl;
			std::string in;
			std::getline(std::cin, in);

			bool is = false;

			for (int i = 0; i < getCorrectAnswers().size(); i++){
				if (getCorrectAnswers()[i] == in) {
					is = true;
					break;
				}
			}

			if (is)finalpoints++;
			else finalpoints--;
		}

		setPoints(finalpoints);
	}

	double grade() override {// make another variable - evaluation and return that!
		return getPoints();
	}

	Question* clone() const override { return new MultipleChoice(*this); }

};