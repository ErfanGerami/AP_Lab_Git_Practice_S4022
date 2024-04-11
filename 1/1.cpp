
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
	Person() {
		name = "";
		age = 0;
	}
	Person(const string& name) {
		this->name = name;

	}
	Person(const string& name, const int age) {
		this->name = name;
		this->age = age;
	}
	string& getName()  { return name; }
	string getName()const { return name; }
	friend class Group;
	friend bool operator< (const Person&, const Person&);
	bool operator== (const Person p) {
		return this->name == p.name && this->age == p.age;
	}
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}
bool operator< (const Person& p1, const Person& p2) {
	return p1.name < p2.name;
}


class Group {
public:

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& g) {
		this->cap = g.cap;
		this->size = g.size;
		this->members = new Person[cap];
		for (int i = 0; i < size; i++) {
			this->members[i] = g.members[i];
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

	~Group() {
		delete[] members;
	}
	friend bool isGroupFull(Group g);
	friend ostream& operator<< (ostream&, const Group&);
	friend Group operator+ (const Group&, const Group&);
	Group& operator= (const Group& g) {
		this->cap = g.cap;
		this->size = g.size;
		delete []this->members;
		this->members = new Person[cap];
		for (int i = 0; i < g.size; i++) {
			this->members[i] = g.members[i];
		}
		return *this;
	}
	Group& operator+= (const Group& g) {
		*this = *this + g;
		return *this;
	}
	private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}
ostream& operator<< (ostream& out, const Group& g) {
	for (int i = 0; i < g.size; i++) {
		cout << g.members[i] << "\t";
	}
	return out;
}
Group operator+ (const Group& g1, const Group& g2) {
	Group temp(g1.cap + g2.cap);
	for (int i = 0; i < g1.size; i++) {
		temp.members[i] = g1.members[i];
	}
	for (int i = g1.size; i < g1.size + g2.size; i++) {
		temp.members[i] = g2.members[i - g1.size];
	}
	temp.size = g1.size + g2.size;
	return temp;
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
	cout << g2 << endl;
	
	
	g3 = g1;
	cout << g3 <<endl;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	cout << g3;
	
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
	if (find(persons,persons+10,Erfan) == persons +10)	return 0;
	cout<<*find(persons,persons+10,Erfan);
	
	








}

