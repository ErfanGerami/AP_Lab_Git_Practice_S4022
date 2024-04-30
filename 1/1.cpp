
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

class Person {
public:
	
	Person(const string& name) {
		this->name = name;

	}
	Person(string s, int g) {
		name = s;
		age = g;
	}
	Person() { name = " ";  age = 0; };
      string& GetName(const string& newName = "") {
		if (!newName.empty()) {
			name = newName;
		}
		return name;
	}
	friend ostream& operator<<(ostream& out, const Person& p);
	const Person& operator=(const Person& other) {

			name = other.name;
			age = other.age;

		return *this;
	}
    string getName() const { return name; }
	void setName(string n) {
		name = n;
	}
	bool operator <( const Person p) const {
		if (strcmp(&name[0], &p.name[0]) > 0)
			return 1;
		return 0;
	}
	bool operator >(const Person p) const {
		if (strcmp(&name[0], &p.name[0]) > 0)
			return 0;
		return 1;
	}
	bool operator ==(const Person p) const {
		if (strcmp(&name[0], &p.name[0]) ==0)
			return 0;
		return 1;
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

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght +1];
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
		cap--;
	}
	Group() {

	}
	Group( const Group& g) {
		this->members = new Person[g.cap + 1];
		size = g.size;
		cap = g.cap;
		for (int i = 0; i < g.cap; i++) {
			members[i] = g.members[i];
		}
	}
	//~Group() {
		//delete[] members;
	//}
	int getSize() { return size; }
	int getCap() { return cap; }
	void setCap(int f) { cap = f; }
	void setSize(int f) { size = f; }
	 friend ostream& operator << (ostream& out, Group p);
	 Group operator +( Group g2)
	 {
		 Group all;
		 int i = 0;
		 all.setCap(cap+ g2.getCap());
		 all.setSize(size + g2.getSize());
		 all.members = new Person[all.getCap()];
		 for (i = 0; i < size; i++)
		 {
			 all.members[i] = members[i];
		 }
		 for (int j = 0; j < g2.getSize(); j++)
		 {
			 all.members[i] = members[j];
			 i++;
		 }
		 return all;



	 }
	 Group operator +=(  Group g2)
	 {
		 Group all;
		 int i = 0;
		 all.size = size + g2.size;
		 all.setCap(cap + g2.cap);
		 all.members = new Person[all.getCap()];
		 for (i = 0; i < cap; i++)
		 {
			 all.members[i] =members[i];
		 }
		 for (int j = 0; j < g2.cap; j++)
		 {
			 all.members[i] =members[j];
				 i++;
		 }
		 *this = all;
		 return *this;



	 }
	 void operator =(const Group g) {
		 members = new Person[g.cap + 1];
		 for (int i = 0; i < g.cap; i++)
			 members[i] = g.members[i];
		 size = g.size;
		 cap = g.cap;
	 }
private:
	int size;
	int cap;
	Person* members;

};
ostream& operator << (ostream& out, Group p) {
	for (int i = 0; i < p.size; i++)
	{
		cout << p.members[i];
		cout<<'\t';
	}
	cout << endl;
	return out;
}


bool isGroupFull(Group g) {
	if(g.getSize() == g.getCap())
	    return 0;
	return 1;

}

int main()
{
	
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2<<endl;
	
	
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
	cout << g3<<endl;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
	
	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].GetName() = to_string(rand() % 100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for (int i = 0; i < 10; i++) {
		cout << persons[i].getName() << ' ';

	}
	cout << endl;
	cout<<*find(persons,persons+10,Erfan)<<endl;

}

