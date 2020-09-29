#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "Ship.h"
using namespace std;

class CargoShip : public Ship
{
	private:
		int cap;
	public:
		// Constructors
		CargoShip(string n, int y, int c);
		~CargoShip();
		
		// Accessors
		int getCap() const;
		// Mutators
		void setCap(int);
		// print function
		virtual void print();
};
#endif