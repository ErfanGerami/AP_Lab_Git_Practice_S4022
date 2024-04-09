#include "Score.h"

int Score::ID_generator = 0;

Score::Score():
ID(Score::ID_generator)
{
	ID_generator++;
}

Score::Score(int score,char *detail, Label label) : ID(Score::ID_generator)
{
    this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

Score::Score(int score,const char *detail, Label label) : ID(Score::ID_generator)
{
    this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}

void Score::setID_generator(int newIdGen){
		Score::ID_generator = newIdGen;
}

void print(const Score& score){
	cout << score.score << " : " << score.detail << endl;
}