
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Person {
public:
	Person() :age(0) {
		name = "";
	}
	Person(const string& name1, const int age1) :age(age1), name(name1) {}
	Person(const string& name) {
		this->name = name;

	}
	friend ostream& operator<<(ostream& out, const Person& p);
	friend class Group;
	string& getName() { return name; }
	string getName()const { return name; }
	void operator=(Person a) {
		this->age = a.age;
		this->name = a.name;
	}
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

	Group(int max_lenght) {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(Group& copy):size(copy.size),cap(copy.cap) {
		this->members = new Person[cap];
		for (int i = 0; i < size; i++) {
			members[i] = copy.members[i];
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
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, const Group& g);
	Group operator+(Group c) {
		Group result(size+c.size);
		for (int i = 0; i < size; i++) {
			result.add(members[i]);
		}
		for (int i = 0; i < c.size; i++) {
			result.add(c.members[i]);
		}
		return result;
	}
	Group& operator +=(Group c) {
		if (cap < size + c.size) {
			Person* n = new Person[size];
			for (int i = 0; i < size; i++) {
				n[i] = members[i];
			}
			delete[] members;
			members = new Person[size + c.size];
			for (int i = 0; i < size; i++) {
				members[i] = n[i];
			}
			cap = size + c.size;
		}
		for (int i = 0; i < c.size;i++) {
			this->add(c.members[i]);
		}
		return *this;
	}
	void operator=(Group c) {
		delete[] members;
		members = new Person[c.cap];
		cap = c.cap;
		size = c.size;
		for (int i = 0; i < c.cap; i++) {
			members[i] = c.members[i];
		}
	}
private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<<(ostream& out, const Group& g) {
	for (int i = 0; i < g.size; i++) {
		out << g.members[i] << "\t";
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
	cout << p1 << p2;
	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout << isGroupFull(g1) << endl;

	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1 << endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;
	
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	cout << endl << g3;
	/*
	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].getName()=to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for(int i=0;i<10;i++){
		cout<<persons[i].getName()<<' ';
	}*/
	/*
	cout<<*find(persons,persons+10,Erfan);
	*/









}

