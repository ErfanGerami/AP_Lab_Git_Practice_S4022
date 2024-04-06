#include "Score.h"
int Score :: ID_generator;
Score :: Score() :ID(Score::ID_generator)
{
	this->score = 0;
	this->label = BAD;
	this->detail = "";
	ID_generator++;
}
Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score& Score:: operator =(const Score& obj) 
{
	this->score = obj.score;
	this->label = obj.label;
	this->detail = obj.detail;
	return *this;
}
void Score :: setID_generator(int _ID)
{
	ID_generator = _ID;
}


