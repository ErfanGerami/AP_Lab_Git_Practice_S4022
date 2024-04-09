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
	Score();
	Score(int score,  char* detail, Label label);
	Score(int score,const char* detail, Label label);
	Score& operator=(Score& cop);
    static void setID_generator(int num);
	friend int main();
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};
#endif


