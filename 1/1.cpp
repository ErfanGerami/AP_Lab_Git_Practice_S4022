#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Group;

class Person {
public:

	Person(const string& name) {
		this->name = name;

	}
	Person() {

		this->name = "";
		this->age = 0;

	}
	Person(const string& N, const int ag) {
		name = N;
		age = ag;
	}

	Person& operator= (Person& p) {
		name = p.name;
		age = p.age;
		return *this;
	}
	bool operator> (Person& p) {
		if (this->name > p.name) {
			return true;
		}
		return false;
	}
	bool operator== (const Person& p)const {
		if (this->name == p.name) {
			return true;
		}
		return false;
	}

	string& getName() { return name; }
	const string& getName()const { return name; }
	friend Group;
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
	Group(Group& gg) {
		this->cap = gg.cap;
		this->size = gg.size;
		this->members = new Person[gg.cap];
		for (int i = 0; i < size; i++) {
			this->members[i] = gg.members[i];
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
		int found = 0;
		for (i = 0; i < size; i++) {
			if (members[i].name == name)
				found = 1;
			break;

		}
		if (found == 0) {
			cout << "Member not found!!" << endl;
			return;
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}

	Group& operator= (const Group& g) {
		this->cap = g.cap;
		this->size = g.size;
		this->members = new Person[g.cap];
		for (int i = 0; i < size; i++) {
			this->members[i] = g.members[i];
		}
		return *this;
	}
	Group operator+ (const Group g) {
		Group G_out(this->cap + g.cap);
		int i = 0;
		for (; i < this->size; i++) {
			G_out.members[i] = this->members[i];
			G_out.size++;
		}
		for (int j = 0; j < g.size; j++, i++) {
			G_out.members[i] = g.members[j];
			G_out.size++;

		}
		return G_out;
	}
	Group& operator += (const Group& g) {
		Person* mem = new Person[g.cap + this->cap];
		int i = 0;
		for (; i < this->size; i++) {

			mem[i] = members[i];

		}
		for (int j = 0; j < g.size; j++, i++) {

			mem[i] = members[j];

		}
		members = mem;
		this->cap += g.cap;
		this->size += g.size;

		return *this;
	}
	~Group() {
		delete[] members;
	}

	friend ostream& operator<<(ostream& out, const Group& p);
	friend bool isGroupFull(Group g);

private:
	int size;
	int cap;
	Person* members;

};
ostream& operator<<(ostream& out, const Group& p) {
	cout << "Capacity: " << p.cap << endl << "Size: " << p.size << endl;
	for (int i = 0; i < p.size; i++) {
		cout << p.members[i] << "    ";
	}
	cout << endl;
	return out;
}
bool isGroupFull(Group g) {
	return (g.size == g.cap);
}
void sort(Person* st, Person* end) {
	int change = 0;
	for (int i = 0; i < end - st; i++) {
		change = 0;
		for (int j = 0; j < (end - st) - 1; j++) {
			if (st[j] > st[j + 1]) {
				Person save;
				save = st[j + 1];
				st[j + 1] = st[j];
				st[j] = save;
				change = 1;
			}
		}
		if (change == 0) {
			break;
		}
	}
}
bool* find(Person* st, Person* end, const Person p) {
	bool AAAA = true;
	bool* b = &AAAA;
	for (int i = 0; i < end - st; i++) {
		if (st[i] == p.getName()) {
			*b = true;
			return b;
		}

	}
	*b = false;
	return b;

}
int main()
{
	srand(time(NULL));
	Person p1("somename");
	Person p2("somename2");
	cout << p1 << endl << p2 << endl;


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
	g3 = g2 + g3;//adds members of g2 and g3 to each other  
	g3 += g3 += g3 += g3;


	Person persons[10];
	Person Erfan("Erfan", 20);
	persons[1] = Erfan;
	for (int i = 0; i < 10; i++) {
		persons[i].getName() = to_string(rand() % 100);
	}
	sort(persons, persons + 10);//what operator should be overloaded for sort? :)
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << persons[i].getName() << ' ';
	}
	cout << endl;
	cout << *find(persons, persons + 10, Erfan);










}

