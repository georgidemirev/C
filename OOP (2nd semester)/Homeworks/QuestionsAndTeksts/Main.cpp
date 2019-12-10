// QuestionsAndTeksts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test.h"

int main()
{

	MultipleChoice q2("Is it okay to kill a person?(You can chose from:(Yes, No, IDK) , and there is 2 correct answers)",
		1, { "No","Yes" ,"IDK"}, {"No" , "IDK"});
	OpenQ q3("Is it okay to kill a person?(open question)", 10);

	Test test({ &q2 });
	test.addQuestion(&q3);
	test.doTest();

	std::cout << test.gradeTest(); 

    return 0;
}

