#include "Employee.h"
#include "libraries.h"

Employee::Employee()
{
	ID = 0;
	address = NULL;
	contact = NULL;
	salary = 0;
	leave = false;
}

Employee::Employee( int age, char* name, char* gender, int ID, char* address, char* contact, double salary )
		: Person(age,name,gender){
	this->address = new char[strlen(address) + 1];
	this->contact = new char[strlen(contact) + 1];
	strcpy(this->address,address);
	strcpy(this->contact,contact);
	this->ID = ID;
	this->salary = salary;
}

Employee::~Employee()
{
	delete [] address;
	delete [] contact;
}

		// Setter Functions

void Employee::setID( int ID )
{
	this->ID = ID;
}

void Employee::setAddress( char* address )
{
	if(this->address == NULL)
	{
		if(address != NULL)
		{
			this->address = new char[strlen(address) + 1];
			strcpy(this->address,address);
		}
	}
	else if(address != NULL)
	{
		strcpy(this->address,address);
	}
}

void Employee::setContact( char* contact )
{
	if(this->contact == NULL)
	{
		if(contact != NULL)
		{
			this->contact = new char[strlen(contact) + 1];
			strcpy(this->contact,contact);
		}
	}
	else if(contact != NULL)
	{
		strcpy(this->contact,contact);
	}
}

void Employee::setSalary( double salary )
{
	this->salary = salary;
}

void Employee::setLeave( bool leave )
{
	this->leave = leave;
}

		// Getter Functions

int Employee::getID() const
{
	return ID;
}
		
char* Employee::getAddress() const
{
	return address;
}

char* Employee::getContact() const
{
	return contact;
}

double Employee::getSalary() const
{
	return salary;
}

bool Employee::getLeave() const
{
	return leave;
}

		// Other Functions
		
void Employee::display() const
{
	Person::display();
	std::cout << "ADDRESS: " << address << std::endl;
	std::cout << "CONTACT#: " << contact << std::endl;
}
