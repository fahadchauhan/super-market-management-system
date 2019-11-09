#include "Worker.h"
#include "libraries.h"

Worker::Worker()
{
	year_of_joining=0;
}

Worker::Worker( int age, char* name, char* gender, int year, int ID, char* address, char* contact, double salary )
		 : Employee(age,name,gender,ID,address,contact,salary)
{
	year_of_joining = year;
}

//			Setter Functions

void Worker::setYear( int year )
{
	year_of_joining = year;
}

//			Getter Functions

int Worker::getYear() const
{
	return year_of_joining;
}

//			Other Functions

void Worker::display() const
{
	Employee::display();
	std::cout << "YEAR OF JOINING: " << year_of_joining << std::endl;
}
