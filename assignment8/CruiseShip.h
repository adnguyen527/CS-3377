#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "Ship.h"
using namespace std;

class CruiseShip : public Ship
{
	private:
		int MAX_PASSENGERS;
	public:
		// Constructors
		CruiseShip(string n, int y, int max);
		~CruiseShip();
		
		// Accessors
		int getMaxPassengers() const;
		// Mutators
		void setMaxPassengers(int);
		// print function
		virtual void print();
};
#endif