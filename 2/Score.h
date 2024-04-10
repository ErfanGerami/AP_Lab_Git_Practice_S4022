#include <iostream>
#include <string>
using namespace std;
#ifndef SCORE
#define SCORE
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
	Score();
	void set_score(int _score);
	void set_label(Label _label);
	void set_detail(string _detail);
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

