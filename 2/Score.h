#pragma once
#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	Score() :ID(Score::ID_generator++), score(0), label(GREAT), detail("") {}
	friend void print(const Score& score);
	friend int main();
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;
	//Score(int score, const char* detail, Label label);

	Score(int score, char* detail, Label label);

	//Score(int score, string& detail, Label label);

	Score(int score, const char* detail, Label label);

	static void setID_generator(int newId);

	//	Score(int score, char* detail, Label label);

	Score& operator = (const Score& score);


private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};
//int Score::ID_generator = 0;




