#include "Score.h"
int Score:: ID_generator = 0;
Score::Score() :ID(Score::ID_generator){
	this->score = 0;
	this->label = GREAT;
	this->detail = "";

	ID_generator++;
} 
Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}


