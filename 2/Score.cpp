#include "Score.h"

int Score::ID_generator = 0;

Score::Score(int score, const char* detail, Label label)
    : score(score), label(label), detail(detail), ID(++ID_generator) {
}

Score::Score()
    : score(0), label(Label::GREAT), detail(""), ID(ID_generator) {
    ID_generator++;
}

Score::Score(const Score& other)
    : score(other.score), label(other.label), detail(other.detail), ID(++ID_generator) {
}

Score& Score::operator=(const Score& other) {
    score = other.score;
    label = other.label;
    detail = other.detail;
    return *this;
}

void print(const Score& score) {
    cout << "Score: " << score << ", Detail: " << detail << ", Label: " << label << ", ID: " << ID << endl;
}

void Score::setID_generator(int value) {
    ID_generator = value;
}

int Score::getID_generator() {
    return ID_generator;
}
