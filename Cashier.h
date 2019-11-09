#ifndef CASHIER_H
#define CASHIER_H

#include "Employee.h"

class Cashier : public Employee{
	private:
		int counter_number;
	public:
		Cashier();
		Cashier( int, char*, char*, int, int, char*, char*, double );
//			Setter Functions
		void setCounter( int );
//			Getter Functions
		int getCounter() const;
//		Other Functions
		void giveCheckOut();
		void display() const;
};

#endif
