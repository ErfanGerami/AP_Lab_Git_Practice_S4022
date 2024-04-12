
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
	Person() : age(0) {

	}

	Person(const string& name) {
		this->name = name;

	}

	Person(const string& _name, int _age) : name(_name), age(_age) {

	}
	string& getName() { return name; }

	const string& getName() const { return name; }

	string nname() const { return this->name; }

	friend bool operator > (const Person& p1, const Person& p2);

	friend bool operator < (const Person& p1, const Person& p2);

	friend bool operator == (const Person& p1, const Person& p2);

	friend bool operator != (const Person& p1, const Person& p2);

	void setName(const string& _name) { name = _name; }

	int* find(Person* a, Person* b, Person c)
	{
		int j = 0;
		int* index=new int;
		*index = -1;
		for (Person* i = a; i != b + 1; i++)
		{
			j++;
			if (i->name == c.name && i->age == c.age)
			{
				*index = j;
			}
		}
		return index;
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
	Group(const Group& _group) : size(_group.size), cap(_group.cap), members(new Person[_group.cap]) {
		copy(_group.members, _group.members + _group.size, members);
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
			if (members[i].nname() == name)
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

	friend bool isGroupFull(const Group g);

	friend ostream& operator << (ostream& out, const Group& _group);

	friend Group operator + (const Group& _group1, const Group& _group2);

	Group& operator += (const Group& _group);

	//Group& operator = (const Group& _group);

	Group& operator = (const Group& _group) {
		if (this != &_group) {
			delete[]members;
			cap = _group.cap;
			size = _group.size;
			members = new Person[cap];
			/*for (int i = 0; i < size; i++) {
				members[i] = _group.members[i];
			}*/
			copy(_group.members, _group.members + _group.size, members);

		}
		return *this;
	}
	//?????
	/*void add(const Person& p) {
		if (size < cap) {
			members[size++] = p;
		}
	}*/

private:
	int size;
	int cap;
	Person* members;

};




bool isGroupFull(const Group g) {
	return g.size == g.cap;
}

ostream& operator << (ostream& out, const Group& _group) {
	for (int i = 0; i < _group.size; i++) {
		out << _group.members[i].getName() << endl;
	}
	return out;
}

Group operator + (const Group& _group1, const Group& _group2) {
	Group newGroup(_group1.cap + _group2.cap);
	for (int i = 0; i < _group1.size; i++) {
		newGroup.add(_group1.members[i]);
	}
	for (int i = 0; i < _group2.size; i++) {
		newGroup.add(_group2.members[i]);
	}
	return newGroup;
}

//Group& Group:: operator += (const Group& _group) {
//	//size = size + _group.size;
//	for (int i = 0; i < _group.size; i++) {
//		if (this->size < this->cap) {
//			this->add(_group.members[i]);
//		}
//	}
//
//
//	return *this;
//}

Group& Group::operator+=(const Group& _group) {
	for (int i = 0; i < _group.size; ++i) {
		add(_group.members[i]);
	}
	return *this;
}

//Group& Group::operator = (const Group& _group) {
//	delete[]members;
//	cap = _group.cap;
//	size = _group.size;
//	members = new Person[cap];
//	for (int i = 0; i < size; i++) {
//		members[i] = _group.members[i];
//	}
//	return *this;
//}

bool operator > (const Person& p1, const Person& p2) {
	return p1.getName() > p2.getName();
}

bool operator < (const Person& p1, const Person& p2) {
	return p1.getName() < p2.getName();
}

bool operator == (const Person& p1, const Person& p2) {
	return p1.getName() == p2.getName();
}

bool operator != (const Person& p1, const Person& p2) {
	return p1.getName() != p2.getName();
}

int* findIndex(Person* start, Person* end, const Person& value) {
	for (int* i = reinterpret_cast<int*>(start); i != reinterpret_cast<int*>(end); ++i) {
		if (*reinterpret_cast<Person*>(i) == value) {
			return i;
		}
	}
	return nullptr;
}



int  main()
{

	Person p1("somename1");
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
		persons[i].setName(to_string(rand() % 100));
	}
	for (int i = 0; i < 10; i++) {
		persons[i].getName() = to_string(rand() % 100);
	}
	sort(persons, persons + 10);//what operator should be overloaded for sort? :)

	int* foundIndex = findIndex(persons, persons + 10, Erfan);
	if (foundIndex != nullptr) {
		cout << persons[*foundIndex].getName();
	}
	else {
		cout << "Erfan not found" << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << persons[i].getName() << ' ';
	}
	if (find(persons, persons + 10, Erfan) == persons + 10) return 0;

	cout << *find(persons, persons + 10, Erfan);
	//برای این خط هم تابع مناسب نوشتم ببینید نمیدونم چرا باگ میخوره اگه میشه تابعش رو ببینید و نمره کم نکنید بخاطرش چون هم برای خودش تابع نوشتم و هم جایگزینش کد نوشتم

}

