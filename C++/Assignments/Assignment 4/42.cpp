#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

using namespace std;


class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner, int year, double km)
        : registrationNo(reg), ownerName(owner), yearOfManufacture(year), kmDriven(km) {
        cout << "[Vehicle Constructor] " << registrationNo << ": " << ownerName << endl;
    }

    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] " << registrationNo << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;
    virtual string vehicleType() const = 0;

    virtual void describe() const {
        cout << "Reg: " << registrationNo << ", Owner: " << ownerName 
             << ", Year: " << yearOfManufacture << ", KM Driven: " << kmDriven;
    }

    double getKmDriven() const { return kmDriven; }
    string getRegNo() const { return registrationNo; }
};

// Car Class (Single Inheritance)
class Car : public Vehicle {
private:
    string fuelType; 
    double mileageKmpl;

public:
    Car(const string& reg, const string& owner, int year, double km, const string& fType, double mileage)
        : Vehicle(reg, owner, year, km), fuelType(fType), mileageKmpl(mileage) {
        cout << "[Car Constructor] " << registrationNo << endl;
    }

    ~Car() override {
        cout << "[Car Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Car"; }

    double fuelCost(double kmToTravel) const override {
        double pricePerLitre = (fuelType == "Petrol") ? 106.00 : 93.00;
        return (kmToTravel / mileageKmpl) * pricePerLitre;
    }

    void describe() const override {
        Vehicle::describe();
        cout << ", Fuel Type: " << fuelType << ", Mileage: " << mileageKmpl << " kmpl";
    }

    string getFuelType() const { return fuelType; }
};

class Truck : public Vehicle {
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg, const string& owner, int year, double km, double payload, double efficiency)
        : Vehicle(reg, owner, year, km), payloadCapacityTons(payload), fuelEfficiencyKmpl(efficiency) {
        cout << "[Truck Constructor] " << registrationNo << endl;
    }

    ~Truck() override {
        cout << "[Truck Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Truck"; }

    double fuelCost(double kmToTravel) const override {
        // Efficiency drops 5% per ton carried
        double effectiveEfficiency = fuelEfficiencyKmpl * (1.0 - (0.05 * payloadCapacityTons));
        double dieselPricePerLitre = 93.00;
        return (kmToTravel / effectiveEfficiency) * dieselPricePerLitre;
    }

    void describe() const override {
        Vehicle::describe();
        cout << ", Payload: " << payloadCapacityTons << " tons, Efficiency: " << fuelEfficiencyKmpl << " kmpl";
    }
};

class ElectricTruck : public Truck {
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:
    ElectricTruck(const string& reg, const string& owner, int year, double km, double payload, double efficiency, double batteryCap, double range)
        : Truck(reg, owner, year, km, payload, efficiency), batteryCapacityKWh(batteryCap), rangePerChargeKm(range) {
        cout << "[ElectricTruck Constructor] " << registrationNo << endl;
    }

    ~ElectricTruck() override {
        cout << "[ElectricTruck Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Electric Truck"; }

    double fuelCost(double kmToTravel) const override {
        double electricityCostPerUnit = 9.50;
        return (kmToTravel / rangePerChargeKm) * batteryCapacityKWh * electricityCostPerUnit;
    }

    void describe() const override {
        Truck::describe();
        cout << ", Battery: " << batteryCapacityKWh << " kWh, Range: " << rangePerChargeKm << " km";
    }
};

class Van : public Vehicle {
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg, const string& owner, int year, double km, int seats, double mileage)
        : Vehicle(reg, owner, year, km), seatingCapacity(seats), mileageKmpl(mileage) {
        cout << "[Van Constructor] " << registrationNo << endl;
    }

    ~Van() override {
        cout << "[Van Destructor] " << registrationNo << endl;
    }

    string vehicleType() const override { return "Van"; }

    double fuelCost(double kmToTravel) const override {
        double petrolPricePerLitre = 106.00;
        return (kmToTravel / mileageKmpl) * petrolPricePerLitre;
    }

    void describe() const override {
        Vehicle::describe();
        cout << ", Seats: " << seatingCapacity << ", Mileage: " << mileageKmpl << " kmpl";
    }
};

void printFleetReport(const vector<Vehicle*>& fleet, double tripKm) {
    cout << "\n===== FLEET REPORT | Trip Distance: " << tripKm << " km =====\n";
    cout << left << setw(15) << "Reg" << setw(18) << "Type" << setw(22) << "Owner" << "Km Driven" << endl;
    cout << string(70, '-') << endl;

    for (const auto* v : fleet) {
        cout << left << setw(15) << v->getRegNo()
             << setw(18) << v->vehicleType()
             << setw(22) << ownerName(v) // helper or direct access if accessible, let's use describe or direct printing
             << v->getKmDriven() << endl;
    }
    
}

int main() {
  
    {
        cout << "--- Stack Object Chain Test ---" << endl;
        ElectricTruck stackET("V-ET001", "Green Logistics", 2024, 15000, 2.0, 8.0, 150.0, 300.0);
        cout << "--- Scope Ending ---" << endl;
    }

    cout << "\n--- Polymorphic Fleet Report Test ---" << endl;
    vector<Vehicle*> fleet;
    fleet.push_back(new Car("KA01AA001", "Ramesh Kumar", 2022, 45200, "Petrol", 15.0));
    fleet.push_back(new Truck("MH04BB002", "Shyam Logistics", 2020, 123500, 3.0, 7.5));
    fleet.push_back(new ElectricTruck("GJ07CC003", "Green Fleet Co", 2023, 89000, 2.0, 6.0, 200.0, 350.0));
    fleet.push_back(new Van("DL02DD004", "Express Couriers", 2021, 67000, 8, 12.0));
    fleet.push_back(new Car("KA05EE005", "Priya Sharma", 2023, 15000, "Diesel", 18.0));

    double tripKm = 200.0;
    cout << "\n===== FUEL / CHARGE COST ESTIMATE =====" << endl;
    Vehicle* mostEfficient = nullptr;
    double minCost = -1.0;

    for (auto* v : fleet) {
        double cost = v->fuelCost(tripKm);
        cout << v->getRegNo() << " (" << v->vehicleType() << "): Rs. " << fixed << setprecision(2) << cost;
        
        if (auto* et = dynamic_cast<ElectricTruck*>(v)) {
            cout << " [Battery: 85% charged]";
        }
        cout << endl;

        if (minCost < 0 || cost < minCost) {
            minCost = cost;
            mostEfficient = v;
        }
    }

    if (mostEfficient) {
        cout << "\nMost Efficient Vehicle: " << mostEfficient->getRegNo() 
             << " (" << mostEfficient->vehicleType() << ") Rs. " 
             << fixed << setprecision(2) << minCost << " for " << tripKm << " km\n" << endl;
    }

    for (auto* v : fleet) {
        delete v;
    }
    fleet.clear();

    return 0;
}