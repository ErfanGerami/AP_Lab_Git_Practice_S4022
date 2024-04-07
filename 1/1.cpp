
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
	Person()
	{
		name = "";
		age = 0;
	}
	Person(const string& name, int age) {
		this->name = name;
		this->age = age;
	}
	string& getName()  { return name; }
	string getName() const  { return name; }
	bool operator <(Person obj)
	{
		int res = name.compare(obj.name);
		return res > 0? 1 : 0;
	}
	bool operator ==(Person const obj)
	{
		int res = name.compare(obj.name);
		return res == 0? 1 : 0; 
	}
	friend ostream& operator<<(ostream& out, const Person& p);
	friend  Group;
private:
	string name;
	int age;

};
ostream& operator<<(ostream& out, const Person& p) 
{
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
	Group(Group& obj)
	{
		size = 0;
		cap = obj.cap;
		members = new Person[obj.cap];
		for(int i = 0; i < obj.size; i++)
			this->add(obj.members[i]);
	}
	~Group() {
		delete[] members;
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
	Group& operator=(const Group& obj)
	{
		size = 0;
		cap = obj.cap;
		members = new Person[obj.cap];
		for(int i = 0; i < obj.size; i++)
			this->add(obj.members[i]);
		return *this;
	}
	Group operator +(Group obj) 
	{
		Group res(cap+obj.cap); 
		int  i;
		res.size = size + obj.size;
		res.members = new Person[cap+obj.cap];
		for(i = 0; i < size; i++)
			res.members[i] = members[i];
		for(i = 0; i < obj.size; i++)
		{
			res.members[i + size] = obj.members[i];
		}
		return res;
	}
	Group& operator +=(Group& obj)
	{
		Group temp(cap+obj.cap);
		temp = *this + obj;
		*this = temp;
		return *this;
	}
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, Group& p);
	friend Person;
private:
	int size;
	int cap;
	Person* members;

};
ostream& operator<<(ostream& out, Group& p) {
	for(int i = 0; i < p.size; i++)
	{
		cout << p.members[i] << '\t';
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
	cout << g1 <<endl;//should cout every person in it with a \t as the separator
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

	cout<< *find(persons,persons+10,Erfan);
}

