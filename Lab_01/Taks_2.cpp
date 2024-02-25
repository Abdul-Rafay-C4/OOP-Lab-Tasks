#include <iostream>

using namespace std;

class house
{
	public:
		string name;
		int age;
		void person_details()
		{
			cout << "Name = " << name << endl;
			cout << "Age  = " << age << " years" << endl;
		}
};
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
			cout << name << " says woof!" << endl;
		}
};

int main()
{
	dog dog1;
	dog1.name = "Jazz";
	dog1.breed = "Haski";
	dog1.age = 3;
	dog1.dog_details();
	
	house person;
	cout << "Person 1"<< endl;
	person.name = "Jazz";
	person.age = 3;
	person.person_details();
	
	house person_2;
	cout << "\nPerson 2"<< endl;
	person_2.name = "Kim";
	person_2.age = 26;
	person_2.person_details();
}