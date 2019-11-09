#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Employee.h"

class Supplier : public Employee{
	private:
		char * category;
		char * company;
	public:
		Supplier();
		Supplier( int, char*, char*, char*, char*, int, char*, char*, double );
		~Supplier();
//			Setter Functions
		void setCategory( char* );
		void setCompany( char* );
//			Getter Functions
		char * getCategory() const;
		char * getCompany() const;
//			Other Functions
		void display() const;
};

#endif
