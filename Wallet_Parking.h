#ifndef WALLET_PARKING_H
#define WALLET_PARKING_H

#include "Employee.h"

class Wallet_Parking : public Employee{
	public:
		Wallet_Parking( int, char*, char*, int, char*, char*, double );
		void parkCar() const;
		void getCar() const;
		void display() const;
};

#endif
