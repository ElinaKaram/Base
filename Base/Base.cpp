#include "Base.h"
#include <iostream>

int Base::people_on_base = 100;
int Base::vehicles_on_base = 10;
double Base::petrol_on_base = 5000;
double Base::goods_on_base = 50;

Vehicle::Vehicle(double petrol, double volume) : petrol_amount(petrol), tank_volume(volume) {}

double Vehicle::getTankVolume() const
{
    return tank_volume;
}

double Vehicle::getPetrolAmount() const
{
    return petrol_amount;
}

void Vehicle::arrive()
{
    Base::vehicles_on_base++;
    Base::people_on_base++;
}

bool Vehicle::leave()
{
    if (Base::petrol_on_base >= (tank_volume - petrol_amount) && Base::people_on_base >= 1) 
    {
        Base::petrol_on_base -= (tank_volume - petrol_amount);
        petrol_amount = tank_volume;
        Base::vehicles_on_base--;
        Base::people_on_base--;
        return true;
    }
    return false;
}

Bus::Bus(int people, int maxPeople, double petrol, double maxPetrol)
: Vehicle(petrol, maxPetrol), people_count(people), max_people(maxPeople) {}

void Bus::arrive() 
{
    Vehicle::arrive();
    Base::people_on_base += people_count;
}

bool Bus::leave()
{
    if (Vehicle::leave())
    {
        int peopleToTake = std::min(max_people, Base::people_on_base);
        Base::people_on_base -= peopleToTake;
        return true;
    }
    return false;
}

Truck::Truck(double load, double maxLoad, double petrol, double maxPetrol)
: Vehicle(petrol, maxPetrol), current_load(load), max_load(maxLoad) {}

void Truck::arrive()
{
    Vehicle::arrive();
    Base::goods_on_base += current_load;
}

bool Truck::leave()
{
    if (Vehicle::leave())
    {
        double loadToTake = std::min(max_load, Base::goods_on_base);
        Base::goods_on_base -= loadToTake;
        return true;
    }
    return false;
}
