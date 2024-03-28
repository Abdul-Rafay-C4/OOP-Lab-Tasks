#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

int main()
{
    // Create a restaurant object
    Restaurant restaurant;
    bool flag = true;
    do
    {
        system("cls");
        cin.ignore();
        // Display available time slots
        restaurant.displayAvailableTimeSlots();
        
        // Reserve a time slot
        string name, contactNumber, timeSlot;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "\nEnter contact number: ";
        getline(cin, contactNumber);
        cout << "\nEnter time slot: ";
        getline(cin, timeSlot);
        int tableNumber = -1;

        if(restaurant.reserveTimeSlot(name, contactNumber, timeSlot, tableNumber))
        {
            cout << "Reservation successful!" << endl;
        }
        else
        {
            cout << "Reservation failed. Time slot already booked or invalid." << endl;
        }
        restaurant.displayAvailableTimeSlots();
        char check;
        bool ch = false;
        do
        {
            cout << "Continue? (y/n): ";
            cin >> check;
            if(check == 'y')
            {
                flag = true;
                ch = true;
            }
            else if(check == 'n')
            {
                flag = false;
                ch = true;
            }
            else
            {
                cout << "Invalid input. Exiting..." << endl;
                flag = false;
                ch = false;
            }
        }while(ch == false);
        
    }while(flag);
    return 0;
}

//define the class methods

// Reservation methods
Reservation::Reservation(string _name, string _contactNumber, string _timeSlot) : name(_name), contactNumber(_contactNumber), timeSlot(_timeSlot) {}

string Reservation::getName() const
{
    return name;
}
string Reservation::getContactNumber() const
{
    return contactNumber;
}
string Reservation::getTimeSlot() const
{
    return timeSlot;
}
//--------------

// Restaurant methods
Restaurant::Restaurant()
{
    // Initialize available time slots (e.g., from 10:00 to 20:00)
    for(int hour = 10; hour <= 20; ++hour)
    {
        availableTimeSlots.push_back(to_string(hour) + ":00");
        availableTimeSlots.push_back(to_string(hour) + ":30");
    }
}

void Restaurant::displayAvailableTimeSlots() const
{
    cout << "Available Time Slots:" << endl;
    for(const string& timeSlot : availableTimeSlots)
    {
        cout << timeSlot << endl;
    }
}

bool Restaurant::reserveTimeSlot(const string& name, const string& contactNumber, const string& timeSlot, int tableNumber)
{
    for (size_t i = 0; i < availableTimeSlots.size(); ++i)
    {
        if (availableTimeSlots[i] == timeSlot)
        {
            availableTimeSlots.erase(availableTimeSlots.begin() + i);
            cout << "Reservation confirmed for " << name << " at " << timeSlot << endl;
            return true;
        }
    }
    cout << "Selected time slot is not available." << endl;
    return false;
}