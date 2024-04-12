
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
	Person(const string& _name, int _age): name(_name),age(_age){}
	
	Person()
	{
		this->name = "";
		this->age = 0;
	}
	
	string& getName()  { return name; }
	
	string getName() const { return name; }
	
	void operator = (Person const p)
	{
		this->name = p.name;
		this->age = p.age;
	}

	bool operator < (Person const p)
	{
		if(this->name < p.name)
			return true;
		else 
			return false;
	}

	bool operator == (Person const p)
	{
		if(this->age == p.age && this->name == p.name)
			return true;
		else 
			return false;
	}
	
	friend class Group;

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

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}

	Group() {
		this->size = 0;
		this->cap = 0;
		this->members = NULL;
	}

	Group(const Group& g) {
		this->size = g.size;
		this->cap = g.cap;
		this->members = new Person[this->cap];

		for (int i = 0; i < this->size; i++) {
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
	Group& operator += (Group const p) {
		Group temp;
		temp.cap = this->cap + p.cap;
		temp.size = this->size + p.size;
		temp.members = new Person[temp.cap];

		for (int i = 0; i < this->size; i++)
		{
			temp.members[i] = this->members[i];
		}
		int i = this->size;
		for (int j = 0; j < p.size; j++)
		{
			temp.members[i] = p.members[j];
			i++;
		}
		*this = temp;
		return *this;
	}
	
	Group operator + (Group const p)
	{
		Group temp;
		temp.cap = this->cap + p.cap;
		temp.size = this->size + p.size;
		temp.members = new Person[temp.cap];
		for (int i = 0; i < this->size; i++)
		{
			temp.members[i] = this->members[i];
		}
		int i = this->size;
		for (int j = 0; j < p.size; j++)
		{
			temp.members[i] = p.members[j];
			i++;
		}
		return temp;
	}
	
	void operator = (Group const g)
	{
		this->size = g.size;
		this->cap = g.cap;
		this->members = new Person[cap];
		for (int i = 0; i < this->size; i++)
		{
			this->members[i] = g.members[i];
		}
	}

	~Group() {
		delete[] members;
	}
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, Group& p);
 
private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

ostream& operator<<(ostream& out, Group& p) {
	for (int i = 0; i < p.size; i++) {
		cout << p.members[i] << "\t";
	}
	return out;
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
	if ((find(persons, persons + 10, Erfan)) >= persons + 10)
		cout << "no result";
	else
		cout << (*find(persons, persons + 10, Erfan)).getName();
	








}

