#ifndef Score_H
#define Score_H
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
	void static setID_generator(int id_generator);
	friend int main();
	Score(int score, const char* detail, Label label);
	Score(int score, char* detail, Label label);
	Score& operator=(const Score& other);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};
#endif



