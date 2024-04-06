#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
	
	Person(const string& name,int age) {
		this->name = name;
		this->age = age;
	}
	
	Person(const string& name) {
		this->name = name;
		this->age = 0;
	}
	
	Person() {
		this->name = "";
		this->age = 0;
	}

	string& getName() { return this->name; }
	string getName() const { return this->name; }
	int getAge() const  { return this->age; }

	Person& operator=(const Person &p){
		this->name = p.getName();
		this->age = p.getAge();
		return *this;
	};

	bool operator<(const Person& other){
		return this->name < other.name;
	}

	bool operator==(const Person& other){
		return this->name == other.name;
	}

private:
	string name;
	int age;

};

ostream& operator<<(ostream& out,const Person& p) {
	out << p.getName() << endl;
	return out;
}

class Group {
public:

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}

	Group(Group& other)  {
		this->cap = other.cap;
		this->members = new Person[other.size];
		for (size_t i = 0; i < other.size; i++)
		{
			this->members[i] = other.members[i];
		}
		this->size = other.size;
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

	friend ostream& operator<<(ostream& out,const Group& g);

	int getCap() const 
	{
		return this->cap;
	}

	int getSize() const 
	{
		return this->size;
	}

	Person* getMembers() const {
		return this->members;
	}

	Group operator+(const Group& other){
		Group result(this->cap + other.cap);
		
		int i;

		for (i = 0; i < this->size; i++)
		{
			result.members[i] = this->members[i];
		}

		for (size_t j = i; j < this->size; j++)
		{
			result.members[j] = this->members[j-i];
		}
		
		return result;
	}

	Group operator+=(const Group& other){
		int oldMembersCount = this->size;

		this->size += other.size;
		this->cap += other.cap;
		Person* oldMembers = new Person[oldMembersCount];

		for (size_t j = 0; j < oldMembersCount; j++)
		{
			oldMembers[j] = this->members[j];
		}
		
		delete [] this->members;

		this->members = new Person[this->size];
		
		for (size_t i = 0; i < oldMembersCount; i++)
		{
			this->members[i] = oldMembers[i];
		}
		
		for (size_t j = oldMembersCount; j < this->size; j++)
		{
			this->members[j] = other.members[j-oldMembersCount];
		}
		
		return *this;
	}

private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<<(ostream& out,const Group& g){
	for (size_t i = 0; i < g.getSize(); i++)
	{
		out << g.getMembers()[i] << '\t';
	}
	
	return out;
}

bool isGroupFull(Group g) {
	return (g.getSize() == g.getCap());
}

int main()
{
	
	// Person p1("somename");
	// Person p2("somename2");
	// cout << p1 << p2;
	
	
	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout<<isGroupFull(g1)<<endl;

	
	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1 << endl; //should cout every person in it with a \t as the separator
	cout << g2 << endl;
	
	
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
	
	// Person persons[10];
	// Person Erfan("Erfan",20);
	// persons[1]=Erfan;
	// for(int i=0;i<10;i++){
	// 	persons[i].getName()=to_string(rand()%100);
	// }
	// sort(persons,persons+10); //what operator should be overloaded for sort? :)

	// for(int i=0;i<10;i++){
	// 	cout<<persons[i].getName()<<' ';
	// }

	
	// cout<<*find(persons,persons+10,Erfan);
	


}

