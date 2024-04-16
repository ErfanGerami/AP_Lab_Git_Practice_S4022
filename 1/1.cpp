/*?????? 
* Complex Number (Part 1)
* AP ??? ?? ????????
* 1403/1/23
* ???????? ?????
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
	
	Person(const string& name) {
		this->name = name;
	}
	Person(const string& _name,int _age) {
		this->name = _name;
		this->age = _age;
	}
	Person() { name = ""; age = 0; }

	//Add distructor
	~Person(){}

	string& getname()  { return name; }
	string getname() const { return name; }

	void setname(string _name) { name=_name; }
	void setage(int _age) { age = _age; }
	int  getage() const { return age; }

	//Overload boolian operator
	bool operator<(const Person& p) { return stoi(name) < stoi(p.name); }
	bool operator==(const Person& p) { return name == p.name; }

	friend class Group;
	friend ostream& operator<<(ostream& out, const Person& p);

private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getname()<<endl;
	return out;
}


class Group {
public:

	Group(int max_lenght) {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(Group& g) {
		this->cap =g.cap;
		this->members = new Person[g.cap];
		this->size = 0;

		for (int i = 0; i < g.size; i++) {
			this->members[i].name = g.members[i].name;
			this->members[i].age = g.members[i].age;
			this->size++;
		}
	}
	Group() {
		cap = 0;
		size = 0;
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

	//Overloading operators
	Group operator+(const Group& g) {
		Group result;
		result.cap = cap + g.cap;
		result.size = size + g.size;
		result.members = new Person[result.cap];

		int i = 0;
		for (i = 0; i < size; i++) {
			result.members[i].name = members[i].name;
			result.members[i].age = members[i].age;
		}

		for (int j = 0; j < g.size; j++) {
			result.members[i].name = g.members[j].name;
			result.members[i].age = g.members[j].age;
			i++;
		}

		return result;
	}

	Group& operator+=(const Group& g) {
		int new_size = size + g.size;
		int new_cap = cap + g.cap;
		Person* new_members = new Person[new_cap];

		for (int i = 0; i < size; i++) {
			new_members[i].name = members[i].name;
			new_members[i].age = members[i].age;
		}

		for (int j = 0; j < g.size; j++) {
			new_members[size + j].name = g.members[j].name;
			new_members[size + j].age = g.members[j].age;
		}

		delete[] members;
		members = new_members;
		size = new_size;
		cap = new_cap;

		return *this;
	}

	Group& operator=(const Group& g) {
		if (this == &g) {
			return *this;
		}

		delete[] members;

		cap = g.cap;
		size = g.size;
		members = new Person[cap];

		for (int i = 0; i < size; i++) {
			members[i].name = g.members[i].name;
			members[i].age = g.members[i].age;
		}

		return *this;
	}
	
	//Friends
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, Group g);

private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<<(ostream& out, Group g) {
	for (int i = 0; i < g.size; i++) {
		out << g.members[i].getname() << "\t";
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
	cout << g3<<endl;
	g3 += g3 += g3 += g3;
	cout << g3;

	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].getname()=to_string(rand()%100);
	}

	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	cout << endl;
	for(int i=0;i<10;i++){
		cout << persons[i].getname() << ' ';
	}
	
	cout << endl << find(persons, persons + 10, Erfan);
}

