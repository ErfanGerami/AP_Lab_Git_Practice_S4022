#include "Score.h"
int Score::ID_generator;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

Score::Score(int score, const char* detail, Label label) : ID(ID_generator)
{
	this->score = score;
	this->detail = detail;
	this->label = label;

	ID_generator++;
}

Score::Score() : ID(ID_generator)
{
	score = 0;
	label = BAD;
	detail = "";
	ID_generator++;
}

void Score::setID_generator(int _ID_generator)
{
	ID_generator = _ID_generator;
}

void print(const Score& score)
{
	cout << "ID : " << score.ID << "\nscore : " << score.score << "\nLabel : " << score.label << "\nDetail : " << score.detail;
}
