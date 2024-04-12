
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	Person (){}
	Person(const string& name) {
		this->name = name;

	}
	Person (string n , int a){
		this->age = a;
		this->name = n;
	}
	string getName() const { return name; }
	bool operator==(const Person& p) const {
    return (name == p.name && age == p.age);
	}
	bool operator<(const Person& p) const {
    return age < p.age;
	}
	friend class Group;
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName() << endl;
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
	~Group() {
		delete[] members;
	}
	int getsize(){return size;}

	Group operator+(const Group& other) {
	Group result(cap + other.cap);
	for (int i = 0; i < getsize(); ++i) {
		result.add(members[i]);
	}
	for (int i = 0; i < other.size; ++i) {
		result.add(other.members[i]);
	}
	return result;
	}
	Group& operator+=(const Group& other) {
    for (int i = 0; i < other.size; ++i) {
        if (isGroupFull(*this)) {
            cout << "Cannot add more members. The group is full." << endl;
            return *this;
        }
        add(other.members[i]);
    }
    return *this;
	}
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, const Group& g);
	
private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<<(ostream& out, const Group& g) {
    for (int i = 0; i < g.size; ++i) {
        out << g.members[i].getName();
        if (i != g.size - 1) {
            out << '\t';
        }
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
	g1.deletePerson("Erfan");
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

