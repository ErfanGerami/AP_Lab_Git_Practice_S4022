
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100

class Person {
public:
	
	Person(const string& name) {
		this->name = name;
		age = 0;
	}
	

	Person(string _name, int _age)
	{
		name = _name;
		age = _age;
	}
	Person()
	{
		name = " ";
		age = 0;
	}

	string getName() const {return name;}
	string& getName()  { return name; }
	void setName(const string& _name) {name = _name;}
	void setAge(int _age) {age = _age;}

    bool operator<(const Person& person) const {
        return name < person.name;
    }
	bool operator==(const Person& person) const
	{
		return (person.name == name);
	}

	friend class Group;

private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	out << p.getName();
	return out;
}




class Group {
public:

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& other) {
        this->cap = other.cap;
        this->size = other.size;
        this->members = new Person[other.cap];

        for (int i = 0; i < other.size; i++) {
            this->members[i] = other.members[i];
        }
    }
	Group(Group& g)
	{
		this->size = g.size;
		this->cap = g.cap;
		this->members = new Person[g.cap];
		for(int i = 0;i < g.size;++i)
		{
			this->members[i] = g.members[i];
		}
	}
	Group& operator=(const Group& other) {
        if (this != &other) {
            delete[] members;
            this->cap = other.cap;
            this->size = other.size;
            this->members = new Person[other.cap];

            for (int i = 0; i < other.size; i++) {
                this->members[i] = other.members[i];
            }
        }
        return *this;
    }
	void add(const Person& p) {
        if (size == cap) {
            return;
        }
        members[size] = p;
        size++;
    }
    void deletePerson(const string& name) {
        int i;
        for (i = 0; i < size; i++) {
            if (members[i].getName() == name)
                break;
        }
        if (i == size) {
            return;
        }
        for (int index = i; index < size - 1; index++) {
            members[index] = members[index + 1];
        }
        members[size - 1].setName("");
        size--;
    }
	Group operator+(const Group& g) const {
        Group res(size + g.size);
        for (int i = 0; i < size; ++i) {
            res.members[i] = members[i];
        }
        for (int i = size, j = 0; i < size + g.size; ++i, ++j) {
            res.members[i] = g.members[j];
        }
        res.size = size + g.size;
        res.cap = size + g.size;
        return res;
    }
	Group& operator+=(const Group& g) {
        cap = size + g.size;
		Person *tmp = new Person[cap];
		for(int i = 0;i < size;++i)
		{
			tmp[i] = members[i];
		}
		members = new Person[cap];
		for(int i = 0;i < size;++i)
		{
			members[i] = tmp[i];
		}
        for (int i = size, j = 0; i < size + g.size; ++i, ++j) {
            members[i] = g.members[j];
            size++;
        }
		delete []tmp;
        return *this;
    }

	friend ostream& operator<< (ostream& out, const Group &g);

	~Group() {
		delete[] members;
	}
	friend bool isGroupFull(const Group& g);

private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<< (ostream& out, const Group &g)
{
	for(int i = 0;i < g.size; ++i)
	{
		out << g.members[i] << '\t';	
	}
	return out;
}

bool isGroupFull(const Group& g) {
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
	
	return 0;
}