#pragma once
#ifndef HEADER_H
#define HEADER_H

const int MAX = 100;

class WebPage {
private:

	char* adress;
	char* ip;

public:

	WebPage();

	WebPage(char* a, char* b);

	~WebPage();

	void print() const;

	void read();

};

class Browser {
private:

	WebPage* webpages = new WebPage[MAX];
	int count;

public:

	Browser();

	Browser(WebPage page, int count);

	Browser(const Browser& copy);

	~Browser();

	void add();

	void out(int);

	void print(int count) const;

	Browser operator+=(const Browser);

};

#endif // !HEADER_H
