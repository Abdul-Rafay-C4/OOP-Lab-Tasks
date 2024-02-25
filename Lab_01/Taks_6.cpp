#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    string make;
    string model;
    int year;
    int mileage;

public:
    Vehicle(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr), mileage(0) 
	{}

    void setMake(string mk)
	{
        make = mk;
    }

    void setModel(string mdl)
	{
        model = mdl;
    }

    void setYear(int yr)
	{
        year = yr;
    }

    void addMileage(int miles)
	{
        mileage += miles;
    }

    bool needsServicing() const
	{
        return mileage >= 10000;
    }

    void displayVehicleInfo() const
	{
        cout << "\nMake: " << make << "\nModel: " << model << "\nYear: " << year << "\nMileage: " << mileage << endl;
    }
};

int main()
{
    Vehicle myVehicle("Toyota", "Corolla", 2020);

    myVehicle.displayVehicleInfo();

    myVehicle.setModel("Camry");
    myVehicle.setYear(2021);
    myVehicle.addMileage(12000);

    myVehicle.displayVehicleInfo();

    if (myVehicle.needsServicing())
	{
        cout << "\nCar needs servicing." << endl;
    }
	else
	{
        cout << "\nCar does not need servicing." << endl;
    }

    return 0;
}
