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
	Score(int score, std::string detail, Label label);
	Score();
	Score(const Score& s);

	void operator=(const Score& s);
	static void setID_generator(int newID);
	friend int main();
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



