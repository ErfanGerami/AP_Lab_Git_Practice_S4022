#include "Score.h"

int Score :: ID_generator;

Score::Score(int score, const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

Score :: Score() : ID(ID_generator) , score(0) , label(GREAT) , detail("") {
	ID_generator++;
}

void Score :: setID_generator(int _ID_generator) {
	ID_generator = _ID_generator;
}

void :: Score :: operator = (const Score& _score){
	this->score = _score.score;
	this->label = _score.label;
	this->detail = _score.detail;
}