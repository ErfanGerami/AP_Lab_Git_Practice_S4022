#include "Score.h"
int Score::ID_generator = 0;
Score::Score() :ID(0) {}
Score::Score(int score, char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;
}
Score::Score(int score, string detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;
}
Score& Score::operator=(const Score& s) {
	this->score = s.score;
	this->label = s.label;
	this->detail = s.detail;
	return *this;
}
void print(const Score& score) {
	cout << "\n\t" << "Score : " << score.score << "\n\t" << "Label : " << score.label << "\n\t";
	cout << "Detail : " << score.detail << "\n\t" << "ID : " << score.ID;
}
void Score::setID_generator(int id) { Score::ID_generator = id; }
