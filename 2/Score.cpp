#include "Score.h"
int Score::ID_generator = 0;

Score::Score(int score, char* detail, Label label) : ID(Score::ID_generator)
{
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;
}

Score::Score(int score, const char* const detail, Label label) : ID(Score::ID_generator)
{
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;
}

int Score::setID_generator(int a)
{
	ID_generator = a;
	return ID_generator;
}

Score& Score::operator=(const Score& score)
{
	this->label = score.label;
	this->detail = score.detail;
	this->score = score.score;
	return *this;
}

void print(const Score& score)
{
	cout << score.ID << " " << score.score << " " << score.label << " " << score.detail;
}