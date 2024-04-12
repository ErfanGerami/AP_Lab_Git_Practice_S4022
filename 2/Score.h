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
	Score(int score, const char* detail, Label label);
	void static setID_generator(int id_generator);
	Score& Score::operator=(const Score& p);
	friend int main();
	//Score::Score() :score(0), label(Label()), detail(""), ID(Score::ID_generator) {};
	void print(const Score&);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

