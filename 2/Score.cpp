#include "Score.h"

Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) 
{
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}
Score::Score() :ID(Score::ID_generator) 
{
	ID_generator++;
}

Score Score::operator=(Score &s)
{
	this->score = s.score;
	this->detail = s.detail;
	this->label = s.label;

	return *this;
}

int Score::setID_generator(int number)
{
	ID_generator = number;
}



