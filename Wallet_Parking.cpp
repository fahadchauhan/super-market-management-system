#include "Wallet_Parking.h"
#include "libraries.h"

Wallet_Parking::Wallet_Parking( int age, char* name, char* gender, int ID, char* address, char* contact, double salary )
		 : Employee(age,name,gender,ID,address,contact,salary) { }

void Wallet_Parking::parkCar() const
{
	
}

void Wallet_Parking::getCar() const
{
	
}

void Wallet_Parking::display() const
{
	Employee::display();
}
