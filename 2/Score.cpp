#include "Score.h"

int Score::ID_generator = 0;

Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) 
{
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}
Score::Score() :ID(Score::ID_generator) 
{
	ID_generator++;
}

Score Score::operator=(Score s)
{
	this->score = s.score;
	this->detail = s.detail;
	this->label = s.label;

	return *this;
}

void Score::setID_generator(int number)
{
	ID_generator = number;
}

void print(const Score& score)
{
	string state[4] = {"GREAT", "GOOD", "NOTBAD", "BAD"};
	cout << "ID : " << score.ID << "	score : " << score.score << "	"<< state[score.label] << "\tdetails : " << score.detail << '\n';
}