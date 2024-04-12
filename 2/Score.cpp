#include "Score.h"

int Score::ID_generator = 0;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score, const char* _detail, Label label) :ID(Score::ID_generator),detail(_detail) {
	this->score = score;
	this->label = label;
	
	ID_generator++;
}
Score::Score(int score, string detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score() :ID(Score::ID_generator) {
	this->score = 0;
	this->detail = "";
	ID_generator++;
}

void Score::setID_generator(int num) { ID_generator = num; }

Score& Score::operator=(const Score& S)
{
	this->score = S.score;
	this->detail = S.detail;
	this->label = S.label;

	return *this;
}

void print(const Score& score)
{
	cout << endl << "ID      -> " << score.ID << endl;
	cout << "Score   -> " << score.score << endl;
	cout << "Lable   -> " << score.label << endl;
	cout << "Detail  -> " << score.detail << endl;
}