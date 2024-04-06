#ifndef Sorce_H
#define Sorce_H

#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score); //dont u forget it in cpp
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;
	Score();
	Score(int score,  char* detail, Label label);
	Score(int score,const char* detail, Label label);
	Score& operator =(const Score& obj);
	static void setID_generator(int _ID);
	friend int main();
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

#endif

