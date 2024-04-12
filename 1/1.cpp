
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	friend class Group;
	Person(){
		name = "";
		age = 0;
	}
	Person(const string& name) {
		this->name = name;

	}
	Person(const string& name, int age){
		this->name = name;
		this->age = age;
	}
	bool operator<(const Person& other) const {
		if(this->name < other.name){
			return true;
		}
		else{
			return false;
		}
	}
	bool operator==(const Person& other) const {
		if(this->name == other.name){
			return true;
		}
		else{
			return false;
		}
	}
	string getName() const { return name; }
	string& getName() { return name; }
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}



class Group {
public:
	friend bool isGroupFull(Group g);
	Group(): size(0), cap(0), members(NULL){}
	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(Group& temp){
		int i;
		this->cap = temp.cap;
		this->size = temp.size;
		this->members = new Person[temp.cap];
		for(i = 0; i < temp.size; i++){
			this->members[i] = temp.members[i];
		}
	}
	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if(members[i].name == name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}
	int get_cap() const {
		return cap;
	}
	int get_size() const {
		return size;
	}
	Person* get_members() const {
		return members;
	}
	Group& operator=(const Group& other){
		int i;
		this->size = other.size;
		this->cap = other.cap;
		delete[] this->members;
		members = new Person[other.cap];
		for(i = 0; i < this->size; i++){
			this->members[i] = other.members[i];
		}
		return *this;
	}
	Group operator+(const Group& other) const {
		int i, j;
		Group answer(this->cap + other.cap);
		answer.size = this->size + other.size;
		for(i = 0; i < this->size; i++){
			answer.members[i] = this->members[i];
		}
		for(j = 0 ; i < this->size + other.size; i++){
			answer.members[i] = other.members[j];
			j++;
		}
		return answer;
	}
	Group& operator+=(const Group other){
		int i, j;
		Group temp;
		temp = *this;
		this->cap = temp.cap + other.cap;
		delete[] this->members;
		this->members = new Person[this->cap];
		this->size = temp.size + other.size;
		for(i = 0; i < temp.size; i++){
			this->members[i] = temp.members[i];
		}
		for(j = 0; i < other.size + temp.size; i++){
			this->members[i] = other.members[j];
			j++;
		}
		return *this;
	}
	~Group() {
		delete[] members;
	}

private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<<(ostream& out, const Group& g) {
	int i;
	cout << "cap : " << g.get_cap() << endl;
	cout << "size : " << g.get_size() << endl;
	for(i = 0; i < g.get_size(); i++){
		cout << g.get_members()[i] << "\t" ;
	}
	return out;
}

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

int main()
{
	int x;
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;
	
	
	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout<<isGroupFull(g1)<<endl;
	
	
	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1<<endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;
	
	
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
	
	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].getName()=to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for(int i=0;i<10;i++){
		cout<<persons[i].getName()<<' ';
	}
	if(find(persons,persons+10,Erfan) != persons + 10){
		cout<<*find(persons,persons+10,Erfan);
	}
	








}

