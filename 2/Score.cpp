#include "Score.h"
int Score::ID_generator = 0; // Initialize to 0 or any other suitable value
Score::Score(int score, string detail , Label l) : ID(Score::ID_generator) {
    this->score = score;
    // this->label = label; // Uncomment this line if needed
    this->detail = detail;
    label = l;
    ID_generator++;
}

void Score::setID_generator(static int h)
{
	ID_generator = h;
}
Score::Score():ID(Score::ID_generator)
{
	ID_generator++;
}
void print(const Score& score) {
    cout << score.detail << endl ;
}
Score::Score( const Score& s):ID(Score::ID_generator)
{
    score = s.score;
    label = s.label;
    detail = s.detail;
}
void Score:: operator=(Score s)
{
    score = s.score;
    label = s.label;
    detail = s.detail;
}

