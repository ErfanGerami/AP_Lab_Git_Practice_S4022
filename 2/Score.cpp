#include "Score.h"
using namespace std;
int Score::ID_generator = 0;
Score :: Score(int score,char* detail, Label label)  : Score::ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
    
	ID_generator++;

}
