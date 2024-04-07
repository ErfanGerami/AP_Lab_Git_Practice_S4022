#include "Score.h"
int Score::ID_generator=0;

Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score& Score::operator=(const Score& other){
	if (this!=&other){
		this->label=other.label;
		this->detail=other.detail;
		this->score=other.score;
	}
	return *this;
}
Score::Score():score(0),label(Label()),detail(""),ID(Score::ID_generator){
	ID_generator++;
}
void Score::setID_generator(int _id_generator){
	ID_generator=_id_generator;
}
void print(const Score& score){
	cout<<"\nthe score:"<<score.score;
	cout<<"\nthe label:"<<score.label;
	cout<<"\nthe detail:"<<score.detail;
	cout<<"\nthe ID:"<<score.ID;
	cout<<"\n";
}