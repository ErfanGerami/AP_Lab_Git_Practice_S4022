#include "Score.h"

int Score::ID_generator = 0;

Score::Score(int score, char *detail, Label label) : ID(Score::ID_generator)
{
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

Score::Score(int score, const char *detail, Label label) : ID(Score::ID_generator)
{
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

Score::Score() : ID(Score::ID_generator), score(0), detail(""), label(BAD)
{
	ID_generator++;
}

void Score::setID_generator(int _ID_generator)
{
	ID_generator = _ID_generator;
}

Score &Score::operator=(const Score &other)
{
	score = other.score;
	label = other.label;
	detail = other.detail;
	return *this;
}

void print(const Score &score)
{
	cout << "score : " << score.score << endl;
	cout << "label : " << score.label << endl;
	cout << "detail: " << score.detail << endl;
	cout << "ID: " << score.ID << endl;
}