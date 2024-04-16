#ifndef SCORE_H
#define SCORE_H

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
	Score(int score,  string detail, Label label);
	Score();

	Score& operator=(const Score& he);

	static void setID_generator(int nw);

	friend int main();

private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

#endif


