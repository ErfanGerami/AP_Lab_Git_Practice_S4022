#include "Score.h"
int Score::ID_generator = 0;
Score::Score(int score, const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;
}
Score::Score() :score(0), label(Label()), detail(""), ID(ID_generator++) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;
}
void Score::setID_generator(int _id_generator) {
	ID_generator = _id_generator;
}
void print(const Score& score) {
	cout << "score:" << score.score;
	cout << "\nlabel:" << score.label;
	cout << "\ndetail:" << score.detail;
	cout << "\nID:" << score.ID;
}
Score& Score::operator=(const Score& p) {
	if (this != &p)
	{
		this->label = p.label;
		this->detail = p.detail;
		this->score = p.score;
	}
	return *this;
}