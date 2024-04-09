#ifndef Score_h
#define Score_h
#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);
	friend int main();
	
	typedef enum 
	{
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score, const char* detail, Label label);
	Score();

	Score operator=(Score s);

	static void setID_generator(int number);
	
	
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

#endif