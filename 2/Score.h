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

	Score(int i, string s, Label l):ID(ID_generator + 1) {
		score = i;
		detail = s;
		label = l;
		ID_generator ++;

	}
	Score() :ID(ID_generator + 1) {
		score = 0;
		detail = "";
		label = NOTBAD;
		ID_generator++;
	}
	Score(int score,  char* detail, Label label);
	Score(int score, const char* detail, Label label);
	Score& operator= (const Score& S) {
		this->score = S.score;
		this->detail = S.detail;
		this->label = S.label;

		return *this;
	}
	static int setID_generator( int id);
	friend int main(); 
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



