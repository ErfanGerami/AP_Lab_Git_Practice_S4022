#include "Score.h"

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
