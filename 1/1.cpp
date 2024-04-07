
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
public:
	bool operator==(const Person &other) const
	{
		return (name == other.name && age == other.age);
	}
	bool operator<(const Person &other) const
	{
		return name < other.name;
	}
	Person(const string &name)
	{
		this->name = name;
	}
	Person(const string &_name, const int &_age) : age(_age), name(_name)
	{
	}
	Person() : name(""), age(0) {}
	Person(const Person &other) : name(other.name), age(other.age) {}
	string &getName() { return name; }
	string getName() const { return name; }
	friend class Group;

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
	friend bool isGroupFull(Group g);
	Group(int max_lenght)
	{
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	// I add an copy constructor for g2(g3)
	Group(const Group &other) : size(other.size), cap(other.cap), members(new Person[other.cap])
	{
		for (int i = 0; i < other.size; ++i)
		{
			this->members[i] = other.members[i];
		}
	}

	int get_size()
	{
		return this->size;
	}
	int get_cap()
	{
		return this->cap;
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

	friend ostream &operator<<(ostream &out, const Group &g);
	Group &operator=(const Group &other)
	{
		if (this != &other)
		{
			delete[] this->members;
			this->size = other.size;
			this->cap = other.cap;
			this->members = new Person[this->cap];
			for (int i = 0; i < this->size; ++i)
			{
				this->members[i] = other.members[i];
			}
		}
		return *this;
	}
	Group operator+(const Group &other)
	{
		int newCapacity = this->cap + other.cap;
		Group result(newCapacity);

		for (int i = 0; i < this->size; ++i)
		{
			result.members[result.size++] = this->members[i];
		}

		for (int i = 0; i < other.size; ++i)
		{
			result.members[result.size++] = other.members[i];
		}
		return result;
	}

	Group &operator+=(const Group &other)
	{
		int newCapacity = this->cap + other.cap;
		Group result(newCapacity);

		for (int i = 0; i < this->size; ++i)
		{
			result.members[result.size++] = this->members[i];
		}

		for (int i = 0; i < other.size; ++i)
		{
			result.members[result.size++] = other.members[i];
		}
		(*this) = result;
		return *this;
	}

private:
	int size;
	int cap;
	Person *members;
};
ostream &operator<<(ostream &out, const Group &g)
{
	out << "the size:" << g.size;
	out << "\n the cap:" << g.cap;
	for (int i = 0; i < g.size; i++)
	{
		out << "\n member" << i + 1 << ":" << g.members[i].getName();
	}
	out << "\n";
	return out;
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
	auto it=find(persons, persons + 10, Erfan);
	if (it!=persons+10){
		cout<<*it;
	}
	else {
		cout<<"\n the person is not found!";
	}
}
