#include <iostream>
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
	        cout << "\nMy dog's name is " << pet.name << endl;
	        pet.bark();
	    }
	
	    void change_pet(dog new_pet)
		{
	        pet = new_pet;
	        cout << "Congratulations! You have a new pet named " << pet.name << endl;
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
	        cin.ignore(); // ignore any remaining newline character in the buffer
	        getline(cin, pr.name);
	        cout << "Enter person age : ";
	        cin >> pr.age;
	        prs.push_back(pr);
	    }
	
	    void list_persons() const
		{
	    int i = 1;
	    for (const auto& pr : prs)
		{
	        cout << "\nPerson " << i << "\nName : " << pr.name << ", \nAge : " << pr.age << endl;
	        ++i;
	    }
	}
	
	    void change_pet(int person_index, dog new_pet)
		{
	        if (person_index >= 0 && person_index < prs.size())
			{
	            prs[person_index].change_pet(new_pet);
	        }
			else
			{
	            cout << "Invalid person index!" << endl;
	        }
	    }
};

class neighborhood
{
	public:
	    vector<house> houses;
	
	    void add_house()
		{
	        house h;
	        int i;
	        cout << "\nEnter how may person live in the house : ";
	        cin >> i;
	        for (int a = 0 ; a < i ; a++)
	        h.add_person(); // Adding a person to the house for demonstration purposes
	        
	        houses.push_back(h);
	    }
	
	    void list_houses()
		{
	        int i = 1;
	        for (const auto& h : houses)
			{
	            cout << "\nHouse " << i << endl;
	            h.list_persons();
	            ++i;
	        }
	    }
};

int main()
{
    neighborhood myNeighborhood;

    char choice;
    do
	{
        cout << "\n1. Add a house\n";
        cout << "2. List all houses and their residents\n";
        cout << "3. Change/Add pet of a person\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
		{
            case '1':
                myNeighborhood.add_house();
                break;
                
            case '2':
                myNeighborhood.list_houses();
                break;
                
            case '3':
			{
                int house_index, person_index;
                cout << "Enter house index: ";
                cin >> house_index;
                cout << "Enter person index: ";
                cin >> person_index;
                dog new_pet;
                cout << "Enter new pet details:\n";
                cout << "Name: ";
                cin.ignore(); // ignore any remaining newline character in the buffer
                getline(cin, new_pet.name);
                cout << "Age: ";
                cin >> new_pet.age;
                cout << "Breed: ";
                cin.ignore(); // ignore any remaining newline character in the buffer
                getline(cin, new_pet.breed);
                myNeighborhood.houses[house_index].change_pet(person_index, new_pet);
                break;
            }
            
            case '4':
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    }while(choice != '4');

    return 0;
}