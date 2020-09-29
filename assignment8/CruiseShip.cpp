#include "CruiseShip.h"
using namespace std;
// Constructors
CruiseShip::CruiseShip(string n, int y, int max):Ship(n,y)
{
	MAX_PASSENGERS = max;
}
CruiseShip::~CruiseShip(){}

// Accessors
int CruiseShip::getMaxPassengers() const
{
	return MAX_PASSENGERS;
}
// Mutators
void CruiseShip::setMaxPassengers(int max)
{
	MAX_PASSENGERS = max;
}
void CruiseShip::print()
{
	cout << "CruiseShip name: " << Ship::getName() << endl;
	cout << "Max Passengers: " << MAX_PASSENGERS << endl;
}