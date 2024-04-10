#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
using namespace std;

class Score {
public:
    friend void print(const Score& score);

    enum Label {
        GREAT,
        GOOD,
        NOTBAD,
        BAD,
    };

    Score();
    Score(int score, const char* detail, Label label);
    Score(const Score& other);
    static void setID_generator(int value);
    static int getID_generator();
    Score& operator=(const Score& other);
private:
    int score;
    Label label;
    string detail;
    const int ID;
    static int ID_generator;
};

#endif
