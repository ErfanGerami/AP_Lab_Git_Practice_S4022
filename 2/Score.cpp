#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

int Score::ID_generator = 0;

Score::Score() : ID(Score::ID_generator) {
	score = 0;
	label = BAD;
	detail = "";
	ID_generator++;
}

void Score::setID_generator(int nw) {
	ID_generator = nw;
}

Score &Score::operator=(const Score &he) {
	score = he.score;
	label = he.label;
	detail = he.detail;
	return *this;
}

Score::Score(int score, string detail, Score::Label label) : ID(ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

void print(const Score& he) {
	cout << he.ID << ' ' << he.detail << ' ' << he.label << ' ' << he.score << endl;
}



