#pragma once
#ifndef BASE_H
#define BASE_H

class Base 
{
public:

    static int people_on_base;
    static int vehicles_on_base;
    static double petrol_on_base;
    static double goods_on_base;
};

class Vehicle
{
protected:

    double petrol_amount;
    double tank_volume;

public:

    Vehicle(double petrol, double volume);
    double getTankVolume() const;
    double getPetrolAmount() const;
    virtual void arrive();
    virtual bool leave();
};

class Bus : public Vehicle 
{
    int people_count;
    int max_people;

public:

    Bus(int people, int maxPeople, double petrol, double maxPetrol);
    void arrive() override;
    bool leave() override;
};

class Truck : public Vehicle
{
    double current_load;
    double max_load;

public:

    Truck(double load, double maxLoad, double petrol, double maxPetrol);
    void arrive() override;
    bool leave() override;
};

#endif