#include "Score.h"
int Score::ID_generator = 1;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score, const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score() :ID(Score::ID_generator) {
	this->score = 0;
	this->label = Score::Label::NOTBAD;
	this->detail = "";
	ID_generator++;
}
Score& Score::operator= (const Score& s) {
	this->score = s.score;
	this->label = s.label;
	this->detail = s.detail;
	return *this;
}
int Score::setID_generator(int id) {
	ID_generator = id;
	return ID_generator;
}
void print(const Score& score) {
	cout << "Score : " << score.score << endl;
	cout << "Lable : " << score.label << endl;
	cout << "Detial : " << score.detail;
	cout << "ID : " << score.ID << endl << "----------------------------";
}