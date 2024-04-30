#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);
	friend int main();
	
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score, string detail, Label label);
	Score();
	Score(const Score& s);
	static void setID_generator(static int h);
	void operator=(Score s);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



