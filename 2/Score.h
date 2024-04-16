#pragma once
#include <iostream>
#include <string>

using namespace std;

class Score {
public:

	friend int main();
	friend void print(const Score& score);
	
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score();
	Score(int score,  char* detail, Label label);
	Score(int score, string detail, Label label);
	Score(int score, const char* _detail, Label label);

	Score& operator=(const Score& S);

	static void setID_generator(int num);
		
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



