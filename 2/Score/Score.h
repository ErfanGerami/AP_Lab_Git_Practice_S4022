#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
using namespace std;

class Score {
public:
    typedef enum Label{
        GREAT,
        GOOD,
        NOTBAD,
        BAD,
    }Label;

    Score(int score, const char* detail, Label label);
    Score();
    Score(const Score& other);
    Score& operator=(const Score& other);

    friend void print(const Score& score);

    static void setID_generator(int value);
    static int getID_generator();

private:
    int score;
    Label label;
    string detail;
    const int ID;
    static int ID_generator;
};

#endif // SCORE_H
