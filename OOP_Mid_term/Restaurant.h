#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Reservation.h"
#include <vector>

class Restaurant
{
    private:
        std::vector<std::string> availableTimeSlots;
        std::vector<Reservation*> reservations;
    public:
        Restaurant();
        void displayAvailableTimeSlots() const;
        bool reserveTimeSlot(const std::string& name, const std::string& contactNumber, const std::string& timeSlot, int tableNumber = -1);
};

#endif
