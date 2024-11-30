#include <iostream>
#include "Base.h"
using namespace std;

int main() 
{
    Bus bus(20, 60, 70, 100);
    Truck truck(40, 50, 60, 150);

    cout << "Initial base stats:" << endl;
    cout << "People: " << Base::people_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;
    cout << "Petrol: " << Base::petrol_on_base << endl;
    cout << "Goods: " << Base::goods_on_base << endl;

    bus.arrive();
    cout << "\nAfter bus arrives:" << endl;
    cout << "People: " << Base::people_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;

    truck.arrive();
    cout << "\nAfter truck arrives:" << endl;
    cout << "Goods: " << Base::goods_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;

    if (bus.leave())
    {
        cout << "\nBus has left the base." << endl;
    }
    else
    {
        cout << "\nBus could not leave the base." << endl;
    }

    if (truck.leave()) 
    {
        cout << "\nTruck has left the base." << endl;
    }
    else
    {
        cout << "\nTruck could not leave the base." << endl;
    }

    cout << "\nFinal base stats:" << endl;
    cout << "People: " << Base::people_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;
    cout << "Petrol: " << Base::petrol_on_base << endl;
    cout << "Goods: " << Base::goods_on_base << endl;

    return 0;
}