// Ship.H
#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
using namespace std;
class Ship
{
	private:
		string name;
		int year;
	public:
		// Constructors
		Ship(string n, int y);
		~Ship();
		
		// Accessors
		string getName() const;
		int getYear() const;
		// Mutators
		void setName(string);
		void setYear(int);
		// virtual print function
		virtual void print();
};
#endif