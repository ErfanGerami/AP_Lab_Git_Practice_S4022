#include "Score.h"
int Score::ID_generator;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

Score::Score(int score, const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

Score::Score(): ID(Score::ID_generator) {
	this->score = 0;
	this->label = NOTBAD;
	this->detail = " ";
	ID_generator++;
}

Score& Score::operator=(const Score& _score){
	this->score = _score.score;
	this->label = _score.label;
	this->detail = _score.detail;
	return *this;
}

void Score::setID_generator(int id) {
	ID_generator = id;
}