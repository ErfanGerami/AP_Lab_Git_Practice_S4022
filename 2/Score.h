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

	Score();
	Score(int score,char* detail, Label label);
	Score(int score,const char* detail, Label label);
	static void setID_generator(int newIdGen);
	friend int main();

	Score& operator=(const Score& other){
		this->score = other.score;
		this->label = other.label;
		this->detail = other.detail;
		return *this;
	}
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};
