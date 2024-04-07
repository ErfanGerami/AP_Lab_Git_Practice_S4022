
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
	Person(const string& _name , int _age  ) : name(_name) , age(_age) { //me
	}
	Person(const string& name) {
		this->name = name;
	}
	Person() { //me
		name = " ";
		age = 0;
	}
	string& getName()  { return name; }
	string getName()const { return name; } //me
	bool operator < (const Person& other) const{ //me
		return this->name < other.name;
	}
	bool operator ==(const Person& other) const { //me
		return  this->name == other.name && this->age == other.age;
	}
	Person* find(Person* start, Person* end,const Person &goal){ //me
		cout << "here";
		for (Person* i = start; i < end; ++i) {
			if (*i == goal) {
				cout << "Hey";
				return i;
			}
		}
		cout << "can not find\n";
		return end ;
	}
	friend class Group;
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) { //check
	cout << p.getName();
	return out;
}



class Group {
public:

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght]; //check
		this->size = 0;
	}
	Group(Group& obj) {
		this->cap = obj.cap;
		this->size = obj.size;
		this->members = new Person[this->cap];
		for (int i = 0; i < this->size; ++i) {
			this->members[i] = obj.members[i];
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
	Group& operator=(const Group& obj) { //me
		this->size = obj.size;
		this->cap = obj.cap;
		this->members = new Person[this->cap];
		for (int i = 0; i < this->size; ++i) {
			this->members[i] = obj.members[i];
		}
		return *this;
	}
	Group operator+(const Group &obj) { //me
		Group sum(this->cap + obj.cap);
		sum.size = this->size + obj.size;
		sum.cap = this->cap + obj.cap;
		for (int i = 0; i < this->size ; ++i) {
			sum.members[i] = this->members[i];
		}
		for (int i = 0; i < obj.size; ++i) {
			sum.members[this->size + i] = obj.members[i];
		}
		return sum;
	}
	Group& operator+=(const Group& obj) { //me
		Group temp(this->cap);
		temp.size = this->size;
		int pirmary_size = obj.size;
		for (int i = 0; i < this->size; ++i) {
			temp.members[i] = this->members[i];
		}
		delete[] this->members;
		this->size = temp.size + obj.size;
		this->cap = this->cap + obj.cap;
		this->members = new Person[this->cap];
		for (int i = 0; i < temp.size ; ++i) {
			this->members[i] = temp.members[i];
		}
		for (int i = 0; i < pirmary_size; ++i) {
			this->members[temp.size + i] = obj.members[i];
		}
		return *this;
	}

	friend bool isGroupFull(Group ); //me
	friend ostream& operator<<(ostream& ,const Group& ); //me
	
	~Group() {
		delete[] members;
	}
	
private:
	int size;
	int cap;
	Person* members;

};
ostream& operator<<(ostream& out ,const Group& obj) { //me
	for (int i = 0; i < obj.size ; ++i) {
		out << obj.members[i] << "\t";
	}
	cout << endl;
	return out;
}

bool isGroupFull(Group g) { //check
	return (g.size == g.cap); 
}

int main()
{
	
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
	cout << g2 << endl ;
	
	
	g3 = g1 ;
	cout << g3  ;
	g3 =  g2 + g3 ;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
	
	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){

		persons[i].getName()=to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for (int i = 0;i<10;i++) {
		cout<<persons[i].getName()<<' ';
	}
	
	
	find(persons,persons+10,Erfan);
	
	








}

