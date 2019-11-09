#include "Guard.h"
#include "libraries.h"

Guard::Guard( int age, char* name, char* gender, int ID, char* address, char* contact, double salary )
		 : Employee(age,name,gender,ID,address,contact,salary) { }

bool Guard::checkBill() const
{
	
}

void Guard::display() const
{
	Employee::display();
}
