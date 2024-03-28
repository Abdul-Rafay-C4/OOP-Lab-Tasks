#ifndef TABLERESERVATION_H
#define TABLERESERVATION_H

#include "Reservation.h"

class TableReservation : public Reservation
{
    private:
        int tableNumber;
    public:
        TableReservation(std::string _name, std::string _contactNumber, std::string _timeSlot, int _tableNumber);
        void displayDetails() const override; // Override displayDetails for specific behavior
        int getTableNumber() const;
    };

#endif
