#include "Score.h"
int Score:: ID_generator = 0;
void Score::setID_generator(int input)
{
	 ID_generator = input;
}

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}
Score::Score(int _score, const char* _detail, Label _label) : ID(Score::ID_generator) {
	this->score = _score;
	this->label = _label;
	this->detail = _detail;

	ID_generator++;
}

Score::Score() : ID(Score::ID_generator) {
	this->score =0;
	this->detail = "";
	this->label = GREAT;
	ID_generator++;
}

Score& Score::operator=(const Score& obj)
{
	this->score = obj.score;
	this->detail = obj.detail;
	this->label = obj.label;
	return *this;
}




