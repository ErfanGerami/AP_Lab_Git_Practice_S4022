
#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <string>
using namespace std;

class Person
{
public:
	friend class Group;
	Person()
	{
		name = "";
		age = 0;
	}
	Person(const string &name)
	{
		this->name = name;
	}
	Person(const string &name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator==(const Person &other) const
	{
		if (this->name == other.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string getName() const { return name; }
	string &getName() { return name; }
	bool operator<(const Person &b) const
	{
		if (this->name < b.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend void deletePerson(string name);

private:
	string name;
	int age;
};

ostream &operator<<(ostream &out, const Person &p)
{
	cout << p.getName();
	return out;
}

class Group
{
public:
	Group() : size(0), cap(0), members(NULL) {}
	friend bool isGroupFull(Group g);
	Group(int max_lenght)
	{
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
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
	void deletePerson(string name)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			if (members[i].name == name)
				break;
		}
		for (int index = i; index < size - 1; index++)
		{
			members[index] = members[index + 1];
		}
		size--;
	}
	~Group()
	{
		delete[] members;
	}
	Group operator+(const Group &b) const
	{
		int i, j;
		Group res(this->cap + b.cap);
		res.size = this->size + b.size;
		for (i = 0; i < this->size; i++)
		{
			res.members[i] = this->members[i];
		}
		for (j = 0; i < this->size + b.size; i++)
		{
			res.members[i] = b.members[j];
			j++;
		}
		return res;
	}
	Group &operator+=(const Group b)
	{
		int i, j;
		Group temp;
		temp = *this;
		this->cap = temp.cap + b.cap;
		delete[] this->members;
		this->members = new Person[this->cap];
		this->size = temp.size + b.size;
		for (i = 0; i < temp.size; i++)
		{
			this->members[i] = temp.members[i];
		}
		for (j = 0; i < b.size + temp.size; i++)
		{
			this->members[i] = b.members[j];
			j++;
		}
		return *this;
	}
	Group &operator=(const Group &b)
	{
		int i;
		this->size = b.size;
		this->cap = b.cap;
		delete[] this->members;
		members = new Person[b.cap];
		for (i = 0; i < this->size; i++)
		{
			this->members[i] = b.members[i];
		}
		return *this;
	}
	friend bool isGroupFull(Group g);
	friend ostream &operator<<(ostream &out, const Group &g);

private:
	int size;
	int cap;
	Person *members;
};

ostream &operator<<(ostream &out, const Group &g)
{
	int i = g.size;
	while (i > 0)
	{
		cout << g.members[i - 1] << " ";
		i--;
	}
}

bool isGroupFull(Group g)
{
	return (g.size == g.cap);
}

int main()
{
	Person p1("somename");
	Person p2("somename2");
	cout << p1 << p2;

	Group g1(5);
	g1.add({"Erfan", 20});
	g1.add({"Saba", 20});
	g1.add({"Mahrokh", 20});
	g1.add({"Yasin", 21});
	cout << isGroupFull(g1) << endl;

	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1 << endl; // should cout every person in it with a \t as the separator
	cout << g2 << endl;

	g3 = g1;
	cout << g3;
	g3 = g2 + g3; // adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;

	Person persons[10];
	Person Erfan("Erfan", 20);
	persons[1] = Erfan;
	for (int i = 0; i < 10; i++)
	{
		persons[i].getName() = to_string(rand() % 100);
	}
	sort(persons, persons + 10); // what operator should be overloaded for sort? :)

	for (int i = 0; i < 10; i++)
	{
		cout << persons[i].getName() << ' ';
	}
	if (find(persons, persons + 10, Erfan) != persons + 10)
	{
		cout << *find(persons, persons + 10, Erfan);
	}
}
