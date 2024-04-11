#include "Score.h"
int Score::ID_generator = 0;
using namespace std;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

void print(const Score& score){
	cout << score.score << " -> " << score.detail << " -> " << score.label << endl;
}
Score::Score(int score, std::string detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score() : ID(Score::ID_generator) {
	this->score = 0;
	this->label = BAD;
	this->detail = "not set yet!";

	ID_generator++;
}
void Score::operator=(const Score& s) {
	score = s.score;
	detail = s.detail;
	label = s.label;
}

void Score::setID_generator(int newID) {
	ID_generator = newID;
}


