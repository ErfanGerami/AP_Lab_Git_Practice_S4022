
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	
public:
	Person(const string& name) {
		this->name = name;
	}
	Person(const string& name,const int& age) {
		this->name = name;
		this->age = age;

	}
	string& getName()  { return name; }
	string getName()const { return name; }

};

ostream& operator<<(ostream& out,const Person& p) {
	cout << p.getName();
	return out;
}
ostream& operator<<(ostream& out, const Group& p) {
	return out;
}


class Group {
public:

	Group(int max_lenght)  {
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
			if(members[i].getName() == name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}
	int getSize() { return size; }
	int getCap() { return cap; }

	~Group() {
		delete[] members;
	}
	Group operator+(Group const& p) {
		return *this;
	}
	Group operator+=(Group const& p) {
		return *this;
	}
private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.getSize() == g.getCap());
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
	cout<<*find(persons,persons+10,Erfan);
	








}

