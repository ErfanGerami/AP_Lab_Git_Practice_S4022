#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Group;
class Person {
public:
	friend class Group;
	Person(){};
	Person(const string& name) 
	{
		this->name = name;
	}
	Person(const string& name, const int& age) 
	{
		this->name = name;
		this->age = age;
	}

	//int

	string& getName() { return name; }
	const string& getName() const{ return name; }

	friend ostream& operator<<(ostream& out, const Person& p);
private:
	string name;
	int age;
};

ostream& operator<<(ostream& out, const Person& p) 
{
	out << p.getName();
	return out;
}

class Group {
public:
	friend class Person;
	Group(int max_lenght)  
	{
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}

	void add(Person p)
	{
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}

	void deletePerson(string name) 
	{
		int i;
		for (i = 0; i < size; i++) 
		{
			if(members[i].name == name)
				break;
		}
		for (int index = i; index < size - 1; index++) 
		{
			members[index] = members[index + 1];
		}
		size--;
	}

	Group operator+(Group g)
	{
		Group return_value(this->cap + g.cap);
		return_value.size = this->size + g.size;

		int i = 0;
		for (i; i < this->size; i++)
		{
			return_value.members[i] = this->members[i];
		}
		for (int j = 0; j < this->size; j++, i++)
		{
			return_value.members[i] = g.members[j];
		}
		return return_value;
	}

	Group operator+=(Group g)
	{
		Group return_value(this->cap + g.cap);
		return_value.size = this->size + g.size;

		int i = 0;
		for (i; i < this->size; i++)
		{
			return_value.members[i] = this->members[i];
		}
		for (int j = 0; j < this->size; j++, i++)
		{
			return_value.members[i] = g.members[j];

		}

		this->size = return_value.size;
		this->cap = return_value.cap;
		delete[] this->members;
		this->members = new Person[this->cap];
		for (i = 0; i < return_value.size; i++)
		{
			this->members[i] = return_value.members[i];
		}

		return return_value;
	}

	friend bool isGroupFull(Group g);
	
	friend ostream& operator<<(ostream& out, const Group& p);

	~Group() 
	{
		delete[] members;
	}

private:
	int size;
	int cap;
	Person* members;
};

bool isGroupFull(Group g) 
{
	return (g.size == g.cap);
}

ostream& operator<<(ostream& out, const Group& p) 
{
	for (int i = 0; i < p.size; i++)
	{
		out << p.members[i].getName() << "\t";
	}
	return out;
}

int main()
{
	/*
	Person p1("somename");
	Person p2("somename2");
	cout << p1 << p2;
	*/
	
	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });

	cout << isGroupFull(g1) << endl;
	
	
	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1 <<endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;
	
	/*
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
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
	}
	
	cout<<*find(persons,persons+10,Erfan);
	*/
}

