
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string>
using namespace std;

class Score {
public:
    friend void print(const Score& score);
    friend int main ();
    typedef enum {
        GREAT,
        GOOD,
        NOTBAD,
        BAD,
    } Label;
	// Score() : score(0), label(GOOD), detail(""), ID(ID_generator++) {}
    Score(int score, const char* detail, Label label); 
    static void setID_generator(int value) {
        ID_generator = value;
    }
    Score() : score(0), label(GREAT), detail(""), ID(ID_generator) {
        ID_generator++;
    }
    Score(int id) : ID(id) {}
    Score(const string& detail) : score(0), label(GREAT), detail(detail), ID(ID_generator) {
    ID_generator++;
    }
    Score(const string& detail, Label label) : detail(detail), label(label) ,  ID (ID_generator) {
        ID_generator ++;
    }
    Score& operator=(const Score& other) {
        // Copy things from other to this
        // ...
        return *this;
    }
private:
    int score;
    Label label;
    string detail;
    const int ID;
    static int ID_generator;
};

#endif 











