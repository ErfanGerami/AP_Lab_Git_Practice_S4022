#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	

    Person()
	{
       name=" ";
	   age=0;

	}
	Person(string _name ,int _age)
	{
		name=_name;
		age=_age;
	}

	Person(const string& name) {
		this->name = name;

	}
	Person(const Person& obj) {
		this->name=obj.name;
		this->age=obj.age;

	}

	string& getName()  { return name; }
     string getName() const {return name;}
     int get_age()   {return age;}
	   bool operator<(const Person& other) const;
	   bool operator == (Person const &obj);
	 Person & operator+(Person const &obj);
     friend class Group;
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}

bool Person ::operator<(const Person& other) const
{
         return name < other.name;
}


class Group {
public:

    Group() : size(0),cap(0)
    {
        this->members = new Person[0];
    }

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}

	Group(const Group& obj) : size(obj.size), cap(obj.cap), members(new Person[obj.cap]) {
    for (int i = 0; i < size; i++) {
        members[i] = obj.members[i];
    }
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
			if(members[i].name == name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}


     Group & operator=(Group const &obj);
    Group & operator +=(Group const &obj);
    Group & operator+(Group const &obj);
    friend ostream& operator<<(ostream& out, const Group& obj);
     
	~Group() {
		delete[] members;
	}

    friend bool isGroupFull(Group g);

private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}


Group& Group::operator=(const Group& obj)
{
    size= obj.size;
    cap = obj.cap;
	for(int i=0 ;i<size ; i++)
	{
		 members[i]=obj.members[i];
	}
    return *this;
}



Group& Group:: operator +=(Group const &obj)
{
	if(size>=obj.size)
	{
           for(int i=0 ; i<size ; i++)
		   {
			members[i]=members[i]+obj.members[i];
		   }
    }

	else
	{
		  size=obj.size;
		  for(int i=0 ; i<size ; i++)
		   {
			members[i]=members[i]+obj.members[i];
		   }

	}
	return *this;
}

Person & Person ::operator+(Person const &obj)
{
           name=name+" "+obj.name;
		   age=age + obj.age;
	       return *this;           
}

Group & Group::operator+(Group const &obj)
{

    for(int i=0 ; i<size ; i++)
	{
		     members[i].name=members[i].name + obj.members[i].name;
			 members[i].age=members[i].age+obj.members[i].age;
	}

	return *this;
           
}

ostream& operator<<(ostream& out, const Group& obj)
{
	for(int i=0 ; i<obj.size ; i++)
	{
		out<<obj.members[i].getName()<<" "<<obj.members[i].get_age()<<endl;
	}
	return out;
    
}



bool Person::operator==( Person const &obj)
{
       return name == obj.name;
}

int main()
{
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<endl<<p2;
	
	
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
	cout<<g3<<endl;
	g3 += g3 += g3 += g3;
	cout<<g3<<endl;
	

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

	 
	  if(find(persons,persons+10,Erfan)!=persons+10)
	     cout<<*find(persons,persons+10,Erfan);

   return 0;
}

