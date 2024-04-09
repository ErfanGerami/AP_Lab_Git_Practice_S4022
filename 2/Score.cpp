#include "Score.h"

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
Score::Score() :ID(Score::ID_generator) {
	this->score = 0;
	this->detail = "";
	ID_generator++;
}
Score& Score::operator=(Score& cop) {
	this->score = cop.score;
	this->detail = cop.detail;
	this->label = cop.label;
	return *this;
}

