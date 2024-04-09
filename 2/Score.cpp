#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
//regarding the main i decided to not use ID_genarator for default constructor.
Score::Score() :ID(ID_generator) {
	this->score = 0;
	this->detail = "";
	this->label = GOOD;
	ID_generator++;
}
Score& Score::operator=(Score& cop) {
	this->score = cop.score;
	this->detail = cop.detail;
	this->label = cop.label;
	return *this;
}
 void print(const Score& score) {
	cout <<"ID: "<<score.ID<< " score: " << score.score;
	if (score.label == score.GREAT) {
		cout << " GREAT ";
	}
	else if (score.label == score.GOOD) {
		cout << " GOOD ";
	}
	else if (score.label == score.BAD) {
		cout << " BAD ";
	}
	else {
		cout << " NOTBAD ";
	}
	cout << score.detail<<endl;
}
  void Score::setID_generator(int num) {
	 ID_generator = num;
 }
