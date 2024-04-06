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
	static void setID_generator(static int h);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



