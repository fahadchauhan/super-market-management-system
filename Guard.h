#ifndef GUARD_H
#define GUARD_H

#include "Employee.h"

class Guard : public Employee{
	public:
		Guard( int, char*, char*, int, char*, char*, double );
		bool checkBill() const;
		void display() const;
};

#endif
