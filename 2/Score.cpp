#include "Score.h"

int Score::ID_generator = 0;


Score::Score(int score, char* detail, Label label) :ID(Score::ID_generator++) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
	ID_generator--;

}

//Score::Score(int score, string& detail, Label label) :ID(Score::ID_generator++) {
//	this->score = score;
//	this->label = label;
//	this->detail = detail;
//}

Score::Score(int score, const char* detail, Label label) :ID(Score::ID_generator++) {
	this->score = score;
	this->label = label;
	this->detail = string(detail);
}


void Score::setID_generator(int newId) {
	ID_generator = newId;
}

Score& Score:: operator = (const Score& score) {
	if (this != &score) {
		this->score = score.score;
		this->label = score.label;
		this->detail = score.detail;
		//this->ID = score.ID;
	}
	return *this;
}



