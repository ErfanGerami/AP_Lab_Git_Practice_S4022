#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person
{
public:
	Person()
	{

	}
	Person(const string& name)
	{
		this->name = name;
	}
	Person(const string& name, const int a)
	{
		this->name = name;
		age = a;
	}
	Person& operator=(const Person& other)
	{
        if (this != &other)
		{
            name = other.name;
            age = other.age;
        }
        return *this;
    }
	const string& getName() const
	{
		return name;
	}
	const int& getAge() const
	{
		return age;
	}
	void setName(string n)
	{
		name = n;
	}
	void setName(string n, int a)
	{
		name = n;
		age = a;
	}
	friend Person* sort(Person * a, Person * b);
	friend int* find(Person * a, Person * b, Person c);
	~Person()
	{
		
	}
private:
	string name;
	int age;
};

bool compareByName(const Person& a, const Person& b)
{
    return a.getName() < b.getName();
}

Person* sort(Person * a, Person * b)
{
	sort(a, b, compareByName);
	return a;
}

int* find(Person * a, Person * b, Person c)
{
	int j = 0;
	int * index;
	*index = -1;
	for(Person *i = a; i != b + 1; i++)
	{
		j++;
		if(i->name == c.name && i->age == c.age)
		{
			*index = j;
		}
	}
	return index;
}

ostream& operator<<(ostream& out, const Person& p)
{
	cout << p.getName();
	return out;
}

class Group {
public:
	Group(int max_lenght)
	{
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& g) 
	{
		size = g.size;
		cap = g.cap;
		this->members = new Person[cap];
		for(int i = 0; i < size; i++)
		{
			members[i].setName(g.members[i].getName(), g.members[i].getAge());
		}
	}
	Group operator=(const Group& g)
	{
		if(cap < g.size)
		{
			cap = g.cap;
		}
		size = g.size;
		this->members = new Person[cap];
		for(int i = 0; i < size; i++)
		{
			members[i].setName(g.members[i].getName(), g.members[i].getAge());
		}
		return g;
	}
	Group operator+(const Group& g)
	{
		Group r(size + g.size);
		r.members = new Person[size + g.size];
		for(int i = 0; i < size; i++)
		{
			r.members[i].setName(members[i].getName(), members[i].getAge());
		}
		for(int i = 0; i < g.size; i++)
		{
			r.members[i + size].setName(g.members[i].getName(), g.members[i].getAge());
		}
		r.size = r.cap;
		return r;
	}
	Group operator+=(const Group& g)
	{
		int s;
		if(cap < size + g.size)
		{
			s = size + g.size;
		}
		else
		{
			s = cap;
		}
		Group r(s);
		for(int i = 0; i < size; i++)
		{
			r.members[i].setName(members[i].getName(), members[i].getAge());
		}
		for(int i = 0; i < g.size; i++)
		{
			r.members[i + size].setName(g.members[i].getName(), g.members[i].getAge());
		}
		r.size = r.cap;
		*this = r;
		return *this;
	}
	void add(Person p)
	{
		if (this->size == this->cap)
		{
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void add(const string& name, int age)
	{
		if (size == cap)
		{
			return;
		}
		members[size] = Person(name, age);
		size++;
	}
	void deletePerson(string name)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			if(members[i].getName() == name)
			{
				break;
			}
		}
		for (int index = i; index < size - 1; index++)
		{
			members[index] = members[index + 1];
		}
		members[size - 1].setName("", 0);
		this->size--;
	}
	friend bool isGroupFull(Group& g);
	friend ostream& operator<<(ostream& out, const Group& g);
	~Group()
	{
		delete[] members;
	}

private:
	int size;
	int cap;
	Person* members;
};

bool isGroupFull(Group& g)
{
	return (g.size == g.cap);
}

ostream& operator<<(ostream& out, const Group& g)
{
	for(int i = 0; i < g.size; i++)
	{
		cout << g.members[i].getName() << g.members[i].getAge() << '\t';
	}
	return out;
}

int main()
{
	
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;
	
	Group g1(5);
	g1.add({"Erfan", 20});
	g1.add({"Saba", 20});
	g1.add({"Mahrokh", 20});
	g1.add({"Yasin", 21});
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
	cout << g3 << endl;
	
	Person persons[10];
	Person Erfan("Erfan", 20);
	persons[1] = Erfan;
	for(int i = 0; i < 10; i++)
	{
		persons[i].setName(to_string(rand() % 100));
	}
	sort(persons, persons + 10);//what operator should be overloaded for sort? :)
	for(int i = 0; i < 10; i++)
	{
		cout << persons[i].getName() << ' ';
	}
	
	cout << *find(persons, persons + 10, Erfan);
}