
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
	Person(const string& name , int g) {
		this->name = name;
		this->age;

	}
	Person() {}
	
	string& getName()  { return name; }
	string getName ()const  {  return  name; }
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
	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void deletePerson(const string &name) {
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
	
	friend bool isGroupFull(const Group& g);
	friend ostream& operator<<(ostream& out, const Group G);
	friend Group operator+(const Group& G1, const Group& G2);
	Group& operator+=( const Group& G2) {
	for (int i = 0; i < size && i < G2.size; i++) {
     members[i] += G2.members[i];
  }
  return *this;
}
private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(const Group& g) {
	return (g.size == g.cap);
}
ostream& operator<<(ostream& out, const Group G) {
	for(int i=0 ; i<G.size ; i++){
		out << G.members[i];
	}
	return out;
}
Group operator+(const Group& G1, const Group& G2) {
  Group result(G1.cap + G2.cap);
  
  for (int i = 0; i < G1.size && i < G2.size; i++) {
    result.members[i] = G1.members[i] + G2.members[i];
  }
  
  result.size = min(G1.size, G2.size);
  
  return result;
}

int main()
{
	
	Person p1("somename");
	//Person p1("somename2");
	Person p2("somename1");
	cout << p1 << p2;
	
	
	Group g1(5);
	g1.add({ "Erfan", 20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout<<isGroupFull(g1)<<endl;
	

	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1<< endl;//should cout every person in it with a \t as the separator
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

