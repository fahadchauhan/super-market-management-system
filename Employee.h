#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
	private:
		int ID;
		char* address;
		char* contact;
		double salary;
		bool leave;
	public:
		Employee();
		Employee( int, char*, char*, int, char*, char*, double );
		virtual ~Employee();
			// Setter Functions
		void setID( int );
		void setAddress( char* );
		void setContact( char* );
		void setSalary( double );
		void setLeave( bool );
			// Getter Functions
		int getID() const;
		char* getAddress() const;
		char* getContact() const;
		double getSalary() const;
		bool getLeave() const;
			// Other Functions
		void display() const;
};

#endif
