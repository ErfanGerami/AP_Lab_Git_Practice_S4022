
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:

	Person(const string& _name, int const _age)
	{
		name = _name;
		age = _age;
	}	
	Person(const string& name) {

		this->name = name;
		age = -1;
	}
	Person()
	{
		name = "";
		age = -1;
	}
	string& getName() { return name; }
	string getName() const {return name;}
	Person& operator = (const Person& p)
	{
		this->age = p.age;
		this->name = p.name;
		return *this;
	}
	bool operator > (const Person p) const
	{
		return name.compare(p.name) > 0;
	}
	bool operator < (const Person p) const
	{
		return name.compare(p.name) < 0;
	}
	bool operator == (const Person p)
	{
		return (age == p.age) && (name == p.name);
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

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& g)
	{
		size = g.size;
		cap = g.cap;
		members = new Person[g.cap];
		for (int i = 0; i < size; i++)
		{
			members[i] = g.members[i];
		}
	}
	int get_size () const
	{
		return size;
	}
	int get_capacity() const
	{
		return cap;
	}
	Person* get_members() const
	{
		return members;
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
	friend bool isGroupFull(Group g);
	Group& operator = (const Group& g)
	{
		int i;
		this->cap = g.cap;
		this->size = g.size;
		this->members = new Person[g.cap];
		for (i = 0; i < size;i++)
		{
			members[i] = g.members[i];
		}
		return *this;
	}
	Group operator + (Group const g)
	{
		int i;
		Group result(cap+g.cap);
		result.size = size + g.size;
		for (i = 0;i < size;i++)
		{
			result.members[i] = members[i];
		}
		for (i = size;i < size + g.size;i++)
		{
			result.members[i] = g.members[i - size];
		}
		return result;
	}
	~Group() {
		delete[] members;
	}
	Group& operator += (const Group& g)
	{
		int i;
		Person* tmp;
		tmp = new Person[g.cap + cap];

		for (i = 0;i < size;i++)
		{
			tmp[i] = members[i];
		}
		for (i = 0;i < g.size;i++)
		{
			tmp[i+size] = g.members[i];
		}
		this->members = tmp;
		cap += g.cap;
		size += g.size;
		return *this;
	}


private:
	int size;
	int cap;
	Person* members;

};

Person* find(Person* start, Person* end, const Person& _person)
{
	Person* i;
	for (i = start;i < end;i++)
	{
		if (*i == _person)
		{
			return i;
		}
	}
	return NULL;
}

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

ostream& operator<<(ostream& out, const Group& g) {
	int i;
	for (i = 0; i < g.get_size();i++)
	{
		cout << g.get_members()[i] << "\t";
	}
	return out;
}

int main()
{
/*
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;
*/
/*
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
	//g3 =  g2 + g3;//adds members of g2 and g3 to each other
	cout << g3 << endl;
	//g3 += g3 += g3 += g3;
	g3 += g2;
	cout << g3<<endl;
	cout << g1;

	*/

	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1] = Erfan;
	for(int i=0;i<10;i++){
		persons[i].getName() = to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for(int i=0;i<10;i++){
		cout<<persons[i].getName()<<' ';
	}
	//persons[9] = Erfan;
	if (!find(persons, persons + 10, Erfan))
	{
		return 0;
	}
	cout << *find(persons, persons + 10, Erfan);
	

	
	








}

