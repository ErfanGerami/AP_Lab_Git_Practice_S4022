#include <iostream>
#include <string>
using namespace std;
#pragma once
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

	Score(int score,  const char* detail, Label label);
	Score();
	void operator = (const Score& _score);
	static void setID_generator(int _ID_generator);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};


