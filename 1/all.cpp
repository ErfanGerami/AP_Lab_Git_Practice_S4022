#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
	Score(int score,  const char* detail, Label label);
	Score & operator =(const  Score & obj);

	static void setID_generator(int x);
	friend int main();
	
	
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

int Score::ID_generator=0;

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;

}

Score::Score():ID(Score::ID_generator)
{
	score=0;
	ID_generator++;
}
Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;
	ID_generator++;

}

void print(const Score& score)
{
    cout<<"score :"<<score.score<<" Label :"<<score.label<<" Name :"<<score.detail<<" ID :"<<score.ID<<" ID_generator :"<<score.ID_generator<<endl;
}

void  Score:: setID_generator(int x)
{
	ID_generator=x;
}

Score& Score::operator=(const Score& obj) {
    score = obj.score;
    label = obj.label;
    detail = obj.detail;
    return *this;
}

int main()
{
	
	srand(time(NULL));

	Score s1(1, "do better next time", Score::BAD);
	Score scores[10];//we have default constructor so we should be fine right?:)
   // cout<<s1;
	FOR(10) {
		SETSCORE(i)
		//why = betwean two scores raises an error?:)
	}
	FOR(10) {
		print(scores[i]);
	}
	Score::setID_generator(Score::ID_generator+100);//just a setter for ID_generator

}

