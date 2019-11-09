#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include "Employee.h"
#include "Customer.h"
#include "Worker.h"

class Admin : public Person{
	private:
		int ID;
		char* password;
		Customer* customer;
		Employee* employee;
	public:
		Admin();
		Admin( int, char*, int, char*, char* );
		~Admin();
		void display() const;
//			Setter Functions
		void setID( int );
		void setPassword( char* );
//			Getter Functions
		int getID() const;
		char* getPassword() const;
//			Customer Handling
		void addCustomer( Customer*, int& );
		void deleteCustomer( Customer*, int& );
		void modifyCustomer( Customer*, int );
		void searchCustomer( Customer*, int );
		void sortCustomer( Customer*, int );
//			Employee Handling
		void addEmployee( Employee*, int& );
		void deleteEmployee( Employee*, int& );
		void modifyEmployee( Employee*, int );
		void increaseSalary( Employee*, int );
		void decreaseSalary( Employee*, int );
		void searchEmployee( Employee*, int );
		void sortEmployee( Employee*, int );
		void giveLeave( Employee*, int );
		void takeLeave( Employee*, int );
};

#endif
