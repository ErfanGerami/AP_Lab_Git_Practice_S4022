
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	friend class Group;
	Person(const string& name) {
		this->name = name;

	}
	Person(const string& name, int age) {
		this->name = name;
        this->age =age;
	}
	Person():age(0),name(" "){};
	string& getName()  { return name; }
	int getAge(){return age;}
	const string& getName() const { return name; }
	void operator = (Person const p) {
		this->name = p.name;
		this->age = p.age;

	}

	bool operator < (Person const p) {
		return ((this->name < p.name) ? true : false);
	}

	bool operator == (Person const p) {
		return ((this->age == p.age && this->name == p.name) ? true : false);
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
    friend class Person;
	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	int get_size(){return size;}
	Person* get_members(){return members;}
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
     void operator = (Group const g) {
		this->size = g.size;
		this->cap = g.cap;
		this->members = new Person[cap];

		for (int i = 0; i < this->size; i++) {
			this->members[i] = g.members[i];
		}

	}
	~Group() {
		delete[] members;
	}
    friend bool isGroupFull(Group g) ;
	friend Group operator+(Group  c1, Group  c2);
private:
	int size;
	int cap;
	Person* members;

};
Group operator+(Group  c1, Group  c2){
	//Group c;

	
}
ostream& operator<<(ostream& out,  Group& p) {
	int i;
	for(i=0;i<p.get_size();++i){
        cout<<p.get_members()[i].getName()<<"\n";
		cout<<p.get_members()[i].getAge()<<"\n";
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
	g1.add({"Erfan",20 });
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
	//g3 += g3 += g3 += g3;
	
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
		cout << "There is no person with this name.";
	else
		cout << (*find(persons, persons + 10, Erfan)).getName();
	








}

