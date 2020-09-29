#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Ship::Ship(string n, int y)
{
	name = n;
	year = y;
}
Ship::~Ship(){}
// Accessors
string Ship::getName() const
{
	return name;
}
int Ship::getYear() const
{
	return year;
}
// Mutators
void Ship::setName(string n)
{
	name = n;
}
void Ship::setYear(int y)
{
	year = y;
}
// virtual print function
void Ship::print()
{
	cout << "Ship name: " << Ship::getName() << endl;
	cout << "Year it was built: " << Ship::getYear() << endl;
}