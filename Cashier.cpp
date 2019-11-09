#include "Cashier.h"
#include "libraries.h"

Cashier::Cashier()
{
	counter_number = 0;
}

Cashier::Cashier( int age, char* name, char* gender, int counter, int ID, char* address, char* contact, double salary )
		 : Employee(age,name,gender,ID,address,contact,salary)
{
	counter_number = counter;
}

//		Setter Functions

void Cashier::setCounter( int counter )
{
	counter_number = counter;
}

//		Getter Functions

int Cashier::getCounter() const
{
	return counter_number;
}

//		Other Functions

void Cashier::giveCheckOut()
{
	// what the heck
}

void Cashier::display() const
{
	Employee::display();
	std::cout << "COUNTER NO: " << counter_number << std::endl;
}
