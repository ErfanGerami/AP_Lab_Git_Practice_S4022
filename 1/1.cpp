
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person {
public:
	Person(const string& _name, const int& _age) {
		name = _name; age = _age;
	}
	Person(const string& name) {
		this->name = name;

	}
	Person() {
		this->name = "";
		this->age = 0;
	}
	string& getName() { return name; }
	const string getName() const{ return  name; }
	bool operator==(const Person& p) {
		return name == p.name && age == p.age;
	}
	bool operator<(const Person& other) const {
		return name < other.name;  // Compare based on name
	}
private:
	friend class Group;
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}



class Group {
public:

	Group(int max_lenght) {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& g) {
		cap = g.cap;
		members = new Person[g.cap];
		size = g.size;
		for (int i = 0; i < size; i++) {
			members[i] = g.members[i];
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
			if (members[i].name == name)
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
	void operator= (const Group & g){

		cap = g.cap;
		
		delete[] members;
		members = new Person[g.cap];
		size = 0;
		for (int i = 0; i < g.size; i++) {
			this->add( g.members[i]);
		}
	}
	Group operator+(const Group& g) {
		Group g1(cap+g.cap);//beacuse dont write any thing about new cap i get it.
		for (int i = 0; i < size; i++)
			g1.add(members[i]);
		for (int i = 0; i < g.size; i++)
			g1.add(g.members[i]);
		return g1;
	}
	Group& operator+=(const Group& g) {		
		Group g1(cap + g.cap);
		for (int i = 0; i < size; i++)
			g1.add( members[i]);
		for (int i =0; i < g.size; i++)
			g1.add (g.members[i]);
		*this = g1;
		return *this;
	}


private:
	int size;
	int cap;
	Person* members;
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, Group p);
};

ostream& operator<<(ostream& out, Group p) {
	for (int i=0; i < p.size; i++) {
		cout << p.members[i].getName() << "\t";
	}
	return out;
}

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

int main()
{
	
	Person p1("somename");
	Person p2("somename2");
	cout << p1 << p2 << endl;
	
	
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
	cout << g3 << endl;
	g3 =  g2 + g1;//adds members of g2 and g3 to each other
	cout << g3 << "g33" << endl;
	g3 += g3 += g3 += g3;
	cout << g3 << endl;
	
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
	
 	Person Erfan2("24",0);//i change this Erfan to Erfan2 beacause Erfan write one time in line 161
	if (find(persons, persons + 10, Erfan2) == persons + 10) {
		cout << endl << "Person not found!" << endl;
		return 0;
	}
	cout << endl << *find(persons, persons + 10, Erfan2);

}

