#pragma once
#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);
	
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score,  char* detail, Label label);
	Score(int score, const char* detail, Label label);
	Score();
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



