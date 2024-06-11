#include "Score.h"

int Score::ID_generator = 0;

Score::Score(int score, char *detail, Label label) : ID(Score::ID_generator)
{
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

void Score::setID_generator(int setter)
{
	ID_generator = setter;
}

void print(const Score &obj)
{
	cout << "score : " << obj.score << endl
		 << "detail : " << obj.detail << endl
		 << "label : " << obj.label << endl
		 << "ID" << obj.ID;
}

Score::Score(int score, const char *detail, Label label) : ID(Score::ID_generator)
{
	this->score = score;
	this->detail = detail;
	this->label = label;
	ID_generator++;
}

Score &Score ::operator=(const Score &b)
{
	this->score = b.score;
	this->label = b.label;
	this->detail = b.detail;
	return *this;
}