#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	Score();
	friend void print(const Score& score);
	void static setID_generator(int set_ID);
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score,  char* detail, Label label);
	friend int main();
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



