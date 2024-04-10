#pragma once
#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print( const Score& score); //check
	friend int main();
	static void setID_generator(int );
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score,  char* detail, Label label);
	Score(int, const char* ,  Label); //me
	Score();//me
	Score& operator=(const Score& obj);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



