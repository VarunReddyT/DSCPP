#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string company_name;
    string model_name;
    string fuel_type;
    float mileage;
    long price;

public:
    Car(string cname, string mname, string ftype, float m, long p)
    {
        cout << endl
             << "Parameterized Constructor" << endl;
        company_name = cname;
        model_name = mname;
        fuel_type = ftype;
        mileage = m;
        price = p;
    }
    Car(Car &car)
    {
        cout << endl
             << "Copy constructor" << endl;
        company_name = car.company_name;
        model_name = car.model_name;
        fuel_type = car.fuel_type;
        mileage = car.mileage;
        price = car.price;
    }
    void displayData()
    {

        cout << endl
             << "=====Display data=====" << endl;
        cout << "Car Company Name. . . " << company_name << endl;
        cout << "Model Name. . . " << model_name << endl;
        cout << "Fuel Type. . . " << fuel_type << endl;
        cout << "Mileage. . . " << mileage << endl;
        cout << "Car Price. . . " << price << endl;
    }
    ~Car()
    {
        cout << endl
             << "Destructor called" << endl;
    }
};
int main()
{
    Car car1("Toyota", "Crysta", "Petrol", 15.5, 1900000);
    car1.displayData();

    Car car2 = car1;
     // Copy constructor called 
    car2. displayData ();

    return 0;
}