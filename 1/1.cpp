#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
	Person() { name = ""; age = 0; }
	Person(const string& name) {
		this->name = name;
	}
	Person(const string& name, const int a) {
		this->name = name;
		this->age = a;
	}
	//Person(const Person& p) { name = p.name; age = p.age; }
	string& getName() { return name; }
	const string& getName() const { return name; }
	//string& getName() const { return name; }
	int getAge() const { return age; }
	void operator= (const Person& p) { this->name = p.getName(); this->age = p.getAge(); }

private:
	string name;
	int age;
	friend class Group;

};

ostream& operator<< (ostream& out, const Person& p) {
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
	Group(const Group& G) {
		this->cap = G.get_cap();
		this->members = new Person[G.get_cap()];
		for (int i = 0; i < G.get_size(); i++)
			this->members[i] = G.members[i];
		this->size = G.get_size();
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
	friend bool isGroupFull(Group g);
	int get_size() const { return this->size; }
	int get_cap() const { return this->cap; }
	Person* get_mems() const { return this->members; }
	Group& operator = (const Group& G) {
		this->cap = G.get_cap();
		this->members = new Person[G.get_cap()];
		for (int i = 0; i < G.get_size(); i++)
			this->members[i] = G.members[i];
		this->size = G.get_size();
		return *this;
	}
	Group& operator += (const Group g1) {
		int priSize = this->size;
		Person* tmp = new Person[this->size];
		for (int i = 0; i < this->size; i++)
			tmp[i] = this->members[i];

		this->cap += g1.get_cap();
		this->members = new Person[this->cap];
		this->size += g1.get_size();
		for (int i = 0; i < priSize; i++) {
			this->members[i] = tmp[i];
		}
		for (int i = g1.get_size(); i < this->size; i++) {
			this->members[i] = g1.get_mems()[i - g1.get_size()];
		}
		return *this;
	}
	Group operator+ (const Group g1) {
		int total_size = g1.get_size() + this->get_size();
		Group newG(this->get_cap()+g1.get_cap());
		for (int i = 0; i < this->get_size(); i++) {
			newG.add(this->get_mems()[i]);
		}
		for (int i = this->get_size(); i < total_size; i++) {
			newG.add(g1.get_mems()[i - this->get_size()]);
		}
		return newG;
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
	for (int i = 0; i < g.get_size(); i++) {
		out << g.get_mems()[i] << "\t";
	}
	return out;
}
bool operator == (const Person& p1, const Person& p2) {
	return p1.getName() == p2.getName();
}
bool operator < (const Person& p1, const Person& p2) {
	return p1.getName() < p2.getName();
}
bool operator <= (const Person& p1, const Person& p2) {
	return p1.getName() <= p2.getName();
}
bool operator > (const Person& p1, const Person& p2) {
	return p1.getName() > p2.getName();
}
bool operator >= (const Person& p1, const Person& p2) {
	return p1.getName() >= p2.getName();
}
bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

int main() {

	Person p1("somename");
	Person p2("somename2");
	cout << p1 << endl << p2 << endl;

	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout << isGroupFull(g1) << endl;
	cout << g1 << endl;/////////////////////////////////////////////////////////

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
	cout << g3 << endl;

	Person persons[10];
	Person Erfan("Erfan", 20);
	for (int i = 0; i < 10; i++) {
		persons[i].getName() = to_string(rand() % 100);
	}
	sort(persons, persons + 10);//what operator should be overloaded for sort? :) answer: <===>=<>

	for (int i = 0; i < 10; i++) {
		cout << persons[i].getName() << " ";
	}

	cout << *find(persons, persons + 10, Erfan);

}

