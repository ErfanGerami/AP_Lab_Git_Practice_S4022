#include "Score.h"

Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

void print(const Score& score) {
    cout << "Score: " << score.score << ", Detail: " << score.detail << ", Label: ";
    switch (score.label) {
    case Score::GREAT:
        cout << "GREAT";
        break;
    case Score::GOOD:
        cout << "GOOD";
        break;
    case Score::NOTBAD:
        cout << "NOTBAD";
        break;
    case Score::BAD:
        cout << "BAD";
        break;
    }
    cout << endl;
} 

