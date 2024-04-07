#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

Score::Score():ID(Score::ID_generator)
{
	score=0;
}

void print(const Score& score)
{
    cout<<"score : "<<score.score<<"Label : "<<score.label<<"Name : "<<score.detail<<"ID : "<<score.ID<<"ID_generator : "<<score.ID_generator<<endl;
}
