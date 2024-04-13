#include "Score.h"

int Score::ID_generator=0;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;

}

Score::Score():ID(Score::ID_generator)
{
	score=0;
	ID_generator++;
}
Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;

}

void print(const Score& score)
{
    cout<<"score :"<<score.score<<" Label :"<<score.label<<" Name :"<<score.detail<<" ID :"<<score.ID<<endl;
}

void  Score:: setID_generator(int x)
{
	ID_generator=x;
}

Score& Score::operator=(const Score& obj) {
    score = obj.score;
    label = obj.label;
    detail = obj.detail;
    return *this;
}

Score ::~Score()
{
   ID_generator --;
}
