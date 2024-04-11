#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Person {
public:
	Person() {}
	Person(string _name, int _age) :name(_name), age(_age) {}
	Person(const string& name) {
		this->name = name;
	}
	string& getName() { return name; }
	bool operator<(const Person& p) {
		if (this->name > p.name)
			return true;
		else
			return false;
	}
	bool operator==(const Person& p) {
		if (this->name == p.name)
			return true;
		else
			return false;
	}
private:
	string name;
	int age;
};

ostream& operator<<(ostream& out, Person& p) {
	out << p.getName();
	return out;
}
class Group {
public:
	Group() :cap(0), size(0), members(NULL) {}
	Group(int max_lenght) {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
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
			if (members[i].getName() == name)
				break;
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}
	int getsize() const { return size; }
	int getcap() const { return cap; }
	Person* getmem() const { return members; }
	Group operator+(const Group& g) {
		Group newg; newg.cap = this->cap + g.cap; newg.size = this->size + g.size;
		int i; newg.members = new Person[newg.cap];
		for (i = 0; i < this->size; i++) {
			newg.members[i] = this->members[i];
		}
		for (int j = 0; j < g.size; j++) {
			newg.members[i + j] = g.members[j];
		}
		return newg;
	}
	Group& operator=(const Group& g) {
		this->cap = g.cap;
		this->size = g.size;
		this->members = new Person[g.cap];
		for (int i = 0; i < this->size; i++)
			this->members[i] = g.members[i];
		return *this;
	}
	Group& operator+=(const Group& g) {
		*this = *this + g; return *this;
	}
	Group(const Group& g) {
		this->cap = g.cap;
		this->size = g.size;
		this->members = new Person[g.cap];
		for (int i = 0; i < this->size; i++)
			this->members[i] = g.members[i];
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
	for (int i = 0; i < g.getsize(); i++) {
		if (i == g.getsize() - 1)
			out << (g.getmem())[i].getName();
		else
			out << (g.getmem())[i].getName() << "\t";
	}
	return out;
}

bool isGroupFull(Group g) {
	return (g.getsize() == g.getcap());
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
	cout << g3 << endl;
	g3 = g2 + g3;//adds members of g2 and g3 to each other
	cout << g3 << endl;
	g3 += g3 += g3 += g3;
	Person persons[10];
	Person Erfan("Erfan", 20);
	persons[1] = Erfan;
	for (int i = 0; i < 10; i++) {
		persons[i].getName() = to_string(rand() % 100);
	}
	sort(persons, persons + 10);//what operator should be overloaded for sort? :)
	for (int i = 0; i < 10; i++) {
		cout << persons[i].getName() << ' ';
	}
	cout << find(persons, persons + 10, Erfan);
}

