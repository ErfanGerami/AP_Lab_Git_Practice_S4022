
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Person
{
public:
	Person()
	{
		this->age = 0;
		this->name = "";
	}
    
	Person(const string &name)
	{
		this->name = name;
	}
	Person(const string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator<(const Person& other) const {
        return name < other.name;
    }
	//friend ostream &operator<<(ostream &out, const Person &p); 
	const string& getName() const { return name; }
	string& getName()  { return name; }
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
	friend bool isGroupFull(const Group &g);
	friend ostream &operator<<(ostream &out, const Group &p);
	~Group()
	{
		delete[] members;
	}
	  Group operator+(const Group &other) const
    {
        Group result(cap + other.cap);
        for (int i = 0; i < size; ++i)
        {
            result.add(members[i]);
        }
        for (int i = 0; i < other.size; ++i)
        {
            result.add(other.members[i]);
        }
        return result;
    }
	
    
	 Group &operator+=(const Group &other)
    {
        if (size + other.size > cap) {
            int newCap = size + other.size;
            Person *newMembers = new Person[newCap];

            for (int i = 0; i < size; ++i)
            {
                newMembers[i] = members[i];
            }
            for (int i = 0; i < other.size; ++i)
            {
                newMembers[size + i] = other.members[i];
            }

            delete[] members;
            members = newMembers;
            size = size + other.size;
            cap = newCap;
        } else {
            for (int i = 0; i < other.size; ++i)
            {
                members[size + i] = other.members[i];
            }
            size = size + other.size;
        }

        return *this;
    }
	 Group &operator=(const Group &other)
    {
        if (this != &other)
        {
            delete[] members;
            size = other.size;
            cap = other.cap;
            members = new Person[other.cap];
            for (int i = 0; i < other.size; ++i)
            {
                members[i] = other.members[i];
            }
        }
        return *this;
    }

private:
	int size;
	int cap;
	Person *members;
};
ostream &operator<<(ostream &out, const Group &g)
{
    for(int i=0;i<g.size;i++){

		cout << g.members[i]<<"\t";
	}
	
	return out;
}

bool isGroupFull(const Group &g)
{
	return (g.size == g.cap);
}

int main()
{

	Person p1("somename");
	Person p2("somename2");
	cout << p1.getName() << p2.getName();

	Group g1(5);
	g1.add({"Erfan", 20});
	g1.add({"Saba", 20});
	g1.add({"Mahrokh", 20});
	g1.add({"Yasin", 21});
	cout << isGroupFull(g1) << endl;
   
	
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
