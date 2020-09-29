#include "CargoShip.h"
using namespace std;
// Constructors
CargoShip::CargoShip(string n, int y, int c):Ship(n,y)
{
	cap = c;
}
CargoShip::~CargoShip(){}

// Accessors
int CargoShip::getCap() const
{
	return cap;
}
// Mutators
void CargoShip::setCap(int c)
{
	cap = c;
}
// print function
void CargoShip::print()
{
	cout << "CargoShip name: " << getName() << endl;
	cout << "Capacity: " << cap << endl;
}