// Factory pattern
#include<iostream>
using namespace std;

// Actual Vehicles will be creating using IVehicle interface.
class IVehicle { public: virtual void Show() = 0; };
// Actual Vehicle classes.
class Bus   : public IVehicle { public: void Show() { cout << "Bus Created."   << endl; } };
class Truck : public IVehicle { public: void Show() { cout << "Truck Created." << endl; } };
class Boat  : public IVehicle { public: void Show() { cout << "Boat Created."  << endl; } };
class Car   : public IVehicle { public: void Show() { cout << "Car Created."   << endl; } };

// Vehicle Factory Interface.
class IVehicleFactory { public: virtual IVehicle* CreateVehicle() = 0; };
//Specific Vehicle Factory.
class BusFactory   : public IVehicleFactory { public: IVehicle* CreateVehicle() { return new Bus()  ; } };
class TruckFactory : public IVehicleFactory { public: IVehicle* CreateVehicle() { return new Truck(); } };
class BoatFactory  : public IVehicleFactory { public: IVehicle* CreateVehicle() { return new Boat() ; } };
class CarFactory   : public IVehicleFactory { public: IVehicle* CreateVehicle() { return new Car()  ; } };

// Create Appropriate Vehicle Factory with the below Abstract Class using Vehicle Factory Interface.
class AbstractFactory {
public:
    static IVehicleFactory* CreateVechicleFactory(const int type) {
        switch (type) {
        case  1: { return new BusFactory()  ; break; }
        case  2: { return new TruckFactory(); break; }
        case  3: { return new BoatFactory() ; break; }
        default: { return new CarFactory()  ; break; }
        }
    }
};

// Factory Pattern Testing.
void FctoryPatternTest()
{
    const int type = 4; // 1 = Bus, 2 = Truck, 3 = Boat, default = Car;

    IVehicleFactory* ivf = AbstractFactory::CreateVechicleFactory(type);    // Create Vehicle Factory.
    IVehicle* ivh = ivf->CreateVehicle();                                   // Create Vehicle .
    ivh->Show();

    delete ivh;
    delete ivf;
}

int main()
{
    FctoryPatternTest();
    return 0;
}