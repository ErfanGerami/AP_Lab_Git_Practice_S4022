#include "Score.h"
int Score::ID_generator=0;
Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score():score(0),label(Label()),detail(""),ID(ID_generator++){

}
void Score::setID_generator(int _id_generator){
	ID_generator=_id_generator;
}
void print(const Score& score){
	cout<<"the score:"<<score.score;
	cout<<"\nthe label:"<<score.label;
	cout<<"\n the detail:"<<score.detail;
	cout<<"\n the ID:"<<score.ID;
}
Score::Score(){
	
}


