#pragma once
#include <iostream>
#include <string>
using namespace std;
class Score
{
public:
	friend void print(const Score& score);
	typedef enum
	{
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;
	Score() : ID(ID_generator++){};
	Score(int score, char* detail, Label label);
	Score(int score, const char* const detail, Label label);
	Score& operator=(const Score&);
	friend int main();
	static int setID_generator(int a);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};