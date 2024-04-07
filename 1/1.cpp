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
	string& getName() { return name; }
    string getName() const {return name;}
	int get_age()   {return age;}
	friend class Group;
     bool operator<(const Person& other) const {
         return name < other.name;
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

    Group() : size(0),cap(0)
    {
        this->members = new Person[0];
    }

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}

   // oprators part
   Group & operator=(Group const &obj);
   Group & operator +=(Group const &obj);
   Group & operator+(Group const &obj);



	 void add(const Person& newGuest) {
        if (this->size == this->cap) {
			return;
		}
		this->members[size] = newGuest;
		this->size++;
    }
  
	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if(members[i].name ==name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}

	void set_size(int _size)
	{
        size=_size;
	}

	void set_cap(int _cap)
	{
		   cap=_cap;
	}
    
	int get_size()
	{
		return size;
	}

	int get_cap()
	{
		return cap;
	}
	// ~Group() {
	// 	delete[] members;
	// }

    friend istream& operator>>(istream& in,Group& obj);
    friend ostream& operator<<(ostream& out, const Group& obj);

    private:
	int size;
	int cap;
	Person* members;

};


istream& operator>>(istream& in, Group& obj)
{
       cout << "Enter size: ";
       in >> obj.size;
       return in;
}

ostream& operator<<(ostream& out, const Group& obj)
{
	for(int i=0 ; i<obj.size ; i++)
	{
		out<<obj.members[i].getName()<<" "<<obj.members[i].get_age()<<endl;
	}
	return out;
    
}


bool isGroupFull(Group g) {
	return (g.get_size() == g.get_cap());
}

Group& Group::operator=(const Group& obj)
{
    size= obj.size;
    cap = obj.cap;
    return *this;
}



Group& Group:: operator +=(Group const &obj)
{
	if(size>=obj.size)
	{
           for(int i=0 ; i<size ; i++)
		   {
			members[i]=obj.members[i];
		   }
    }

	else
	{
		  size=obj.size;
		  for(int i=0 ; i<size ; i++)
		   {
			members[i]=obj.members[i];
		   }

	}
	return *this;
}

Group & Group::operator+(Group const &obj)
{
	    for(int i=0 ; i<size ; i++)
		{
			
		}
        return *this;  
}



int main()
{
	
	Person p1("somename");
	Person p2("somename2");
	//cout << p1<<endl<<p2;
	
	
	Group g1(5);
	
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	//cout<<isGroupFull(g1)<<endl;
	
	
	Group g2(g1);
	Group g3(10);
	///cout << g1<<endl;//should cout every person in it with a \t as the separator
	g2.deletePerson("Erfan");
   // cout << g2 << endl;
    
	/*
     Group g2(g1);
     Group g3(10);
     g2.deletePerson("Erfan");
     cout << g1 << endl;
     cout << g2 << endl;

    */
	
	g3 = g1;
	//cout << g3;
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

	/*
	cout<<*find(persons,persons+10,Erfan);
	*/
   return 0;
}

