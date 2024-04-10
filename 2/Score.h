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

	Score(int score, const char* detail, Label label);
	Score();
	void set_score(int _score);
	void set_label(Label _label);
	void set_detail(const string& _detail);
	void setID_generator(int id_g);

	~Score();
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

#endif

