/*
** Assignment: hmw_5_2.cpp
** Author    : Max Aliprandi
** Class     : PIC10A
*/
#include <iostream>

using namespace std;

//function PROTOTYPES
class Car
{
public:
  Car();
  Car(double cfuel_efficiency);
  double get_gas() const;
  double get_fuel_efficiency() const;
  double drive(double miles);
  void add_gas(double cgas);
  void set_gas(double g);

private:
  double fuel_efficiency; //in miles/gallon
  double gas; //in gallons
};

//main FUNCTION
int main()
{
  char x;
  double fuel_ef;
  double gals;
  double miles;
  double mils_left;
//User input

  cout << "Enter the car's fuel efficiency: ";
  cin >> fuel_ef;
  if(fuel_ef < 0 || !cin)
  {
    cout << "Incorrect input. Exit!\n";
    return 0;
  }
  Car c(fuel_ef);

  while(true)
  {
    cout << "Gas to add (gallons): ";
    cin >> gals;
    if(gals < 0 || !cin)
    {
      cout << "Incorrect input. Exit!\n";
      break;
    }
    c.add_gas(gals); //adds gas to previous amount of gas

    cout << "Miles to drive: ";
    cin >> miles;
    if(miles < 0 || !cin)
    {
      cout << "Incorrect input. Exit!\n";
      break;
    }
    cout << "\n";

    double rem = c.drive(miles);

    if(rem <= 0)
    {
      cout << "Done! Fuel remains: " << gals-(miles/fuel_ef) << endl;
    } else
    {
      cout << "We ran out of fuel! " << rem << " miles remain." << endl;
    }

    cout << "Continue? (y/n) ";
    cin >> x;
    cout << "\n";
    if (x == 'n') break;
  }
  return 0;
}

//function DEFINITIONS

Car::Car(double cfuel_efficiency)
{
  fuel_efficiency = cfuel_efficiency;
}

double Car::get_gas() const
{ return gas; }

double Car::get_fuel_efficiency() const
{ return fuel_efficiency; }

double Car::drive(double miles) //number of miles left in trip
{
  double miles_left = miles;
  double g = get_gas();
  double f = get_fuel_efficiency();
  double miles_drivable = g*f;

  if(miles_left > miles_drivable) //if remaining miles after gas is empty
  {
    return miles_left - miles_drivable; //returns total drivable distance
  }
  else //enough gas to complete drive
  {
    miles_left = 0;
    set_gas(gas-(miles/fuel_efficiency)); //adjusts for remaining gas
    return miles_left;
  }
}

void Car::set_gas(double g)
{
  gas = g;
}

void Car::add_gas(double cgas)
{
  gas = gas + cgas;
}
