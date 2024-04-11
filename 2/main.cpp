#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Score.h"
#include <ctime>
#include "SomeRandomDotHFile.h"
using namespace std;

#define FOR(n) for(int i=0;i<n;i++)
#define SETSCORE(i) int score = rand() % 20 + 1; scores[i] = Score(score, ("some string " + to_string(i)).c_str(), Score::Label(3 - score / 5))



int main() {

    srand(time(NULL));

    Score s1(1, "do better next time", Score::BAD);
    Score scores[10]; //we have default constructor so we should be fine right?:)

    FOR(10) {
        SETSCORE(i);
        //why = between two scores raises an error?:)
    }

    FOR(10) {
        print(scores[i]);
    }

    Score::setID_generator(Score::getID_generator() + 100); //just a setter for ID_generator

    return 0;
}
