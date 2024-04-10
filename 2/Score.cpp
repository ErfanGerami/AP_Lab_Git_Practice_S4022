#include "Score.h"

int Score::ID_generator = 0;

Score::Score() : score(0), detail(""), label(NOTBAD), ID(ID_generator++) {}
Score::Score(int score, const char* detail, Label label) : ID(ID_generator) {
    this->score = score;
    this->label = label;
    this->detail = detail;

    ID_generator++;
}
Score::Score(const Score& other) : score(other.score), label(other.label), detail(other.detail), ID(ID_generator++) {}

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
            cout << "NOT BAD";
            break;
        case Score::BAD:
            cout << "BAD";
            break;
    }
    cout << endl;
}
Score& Score::operator=(const Score& other) {
    if (this != &other) {
        this->score = other.score;
        this->label = other.label;
        this->detail = other.detail;
    }
    return *this;
}
void Score::setID_generator(int value) {
    ID_generator = value;
}
int Score::getID_generator() {
    return ID_generator;
}
