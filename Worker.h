#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"

class Worker : public Employee{
	private:
		int year_of_joining;
	public:
		Worker();
		Worker( int, char*, char*, int, int, char*, char*, double );
//			Setter Functions
		void setYear( int );
//			Getter Functions
		int getYear() const;
//			Other Functions
		void display() const;
};

#endif
