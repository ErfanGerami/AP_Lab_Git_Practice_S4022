#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);
	
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score,  char* detail, Label label);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};


void print(const Score& score);