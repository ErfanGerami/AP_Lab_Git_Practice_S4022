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
	Score();
	Score(int score, const char* detail, Label label);
	
	
	Score& operator=(const Score& other) {

		if (this != &other) {

			this->score = other.score;
			this->label = other.label;
			this->detail = other.detail;
		}

		return *this;
	}
	static void setID_generator(int value) {
		ID_generator = value;
	}
	
	
	
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



