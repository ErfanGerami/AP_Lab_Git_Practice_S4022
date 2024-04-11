#pragma once
#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);
	friend int main();
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score,  char* detail, Label label);
	Score(int score, const char* detail, Label label);
	Score();
	static void setID_generator(int input);
	Score operator =(const Score s);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



