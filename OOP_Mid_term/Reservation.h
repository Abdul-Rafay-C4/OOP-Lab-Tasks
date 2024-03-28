#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation
{
    private:
        std::string name;
        std::string contactNumber;
        std::string timeSlot;
    public:
        Reservation(std::string _name, std::string _contactNumber, std::string _timeSlot);
        std::string getName() const;
        std::string getContactNumber() const;
        std::string getTimeSlot() const;
};

#endif
