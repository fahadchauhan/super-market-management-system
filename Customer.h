#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Account.h"

class Customer : public Person
{
	private:
		char * address;
		char * contact;
		Account * account;
	public:
		Customer();
		Customer( int, char*, char*, double, char*, char*, int, char*, char* );
		~Customer();
//			Setter Functions
		void setAddress( char* );
		void setContact( char* );
//			Getter Functions
		char * getAddress() const;
		char * getContact() const;
//			Account Functions
		void setNumber( int );
		void setPassword( char* );
		void setType( char* );
		void setBalance( double );
		void depositBalance( double );
		int getAccountNumber() const;
		char* getPassword() const;
		double getBalance() const;
		char* getType() const;
		void deductBalance(double);
//			Other Functions
		void createAccount();
		void removeAccount(char*);
		void modifyAccount();
		void display() const;
};

#endif
