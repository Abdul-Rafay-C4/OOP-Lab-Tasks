#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class dog
{
	public:
		string name;
		string breed;
		int age;
		void dog_details()
		{
			cout << "Name  = " << name << endl;
			cout << "Age   = " << age << " years" << endl;
			cout << "Breed = " << breed << endl;
		}
		void bark()
		{
			cout << name << " says woof!" << endl;
		}
};

class person
{
		public:
		string name;
		int age;
		dog pet;
		void person_details()
		{
			cout << "Name = " << name << endl;
			cout << "Age  = " << age << " years" << endl;
		}
		void into_pet()
		{
			cout << "\nMy dog name is " << pet.name << endl;
			pet.bark();
		}
		void new_pet()
		{
			
		}
};

class house
{
	public:
		vector<person> prs;
		void add_person()
		{
			person pr;
			cout << "\nEnter person name : ";
			getline(cin,pr.name);
			cout << "\nEnter person age : ";
			cin >> pr.age;
			prs.push_back(pr);
		}
		
		void list_person()
		{
			int i = 1;
			for(const auto &pr : prs)
			{
				cout << "\nPerson " << i << "\nName : " << pr.name << ", \nAge : " << pr.age << endl;
				++i;
			}
		}
};

int main()
{
	
}