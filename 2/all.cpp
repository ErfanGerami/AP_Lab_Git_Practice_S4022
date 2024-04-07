#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Score.h"
using namespace std;
#define FOR(n) for(int i=0;i<n;i++)
#define SETSCORE(i) int score=rand()%20+1;/*no 0s*/\
scores[i] = Score( score,("some string " + to_string(i)).c_str(),Score::Label(3-score/5)) ;


class Score {
public:
	friend void print(const Score& score);
	
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

    Score();
	Score(int score,  char* detail, Label label);
	static void setID_generator(int x)
	{

	}
    
	friend int main();
	
	
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};


Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

Score::Score():ID(Score::ID_generator)
{
	score=0;
}

void print(const Score& score)
{
    cout<<"score : "<<score.score<<"Label : "<<score.label<<"Name : "<<score.detail<<"ID : "<<score.ID<<"ID_generator : "<<score.ID_generator<<endl;
}

int main()
{
	
	srand(time(NULL));

	Score s1(1, "do better next time", Score::BAD);
	Score scores[10];//we have default constructor so we should be fine right?:)

	FOR(10) {
		SETSCORE(i)
		//why = betwean two scores raises an error?:)
	}
	FOR(10) {
		print(scores[i]);
	}
	Score::setID_generator(Score::ID_generator+100);//just a setter for ID_generator

}

