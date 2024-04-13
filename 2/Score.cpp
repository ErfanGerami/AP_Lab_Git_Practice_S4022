#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(){
	this->score = -0;
	
	this->detail = "";

	ID_generator=0;
}

