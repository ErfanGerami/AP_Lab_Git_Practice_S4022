#include "Score.h"
int Score::ID_generator = 0;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;

}
Score::Score(int s, string d, Label l):ID(ID_generator) {
		this->score = s;
		this->detail = d;
		this->label = l;
		ID_generator ++;

	}
Score::Score():ID(ID_generator) {
		score = 0;
		detail = "";
		label = NOTBAD;
		ID_generator++;
	}
Score& Score::operator= (const Score& s) {
		score = s.score;
		detail = s.detail;
		label = s.label;
		return *this;
	}
void print(const Score& s) {
	cout << "Score: " << s.score << endl << "Detail: " << s.detail << endl << "Lable: " << s.label << endl << "ID: " << s.ID << endl;
}
void setID_generator(int id) {
	Score::ID_generator = id;
	return ;
}


