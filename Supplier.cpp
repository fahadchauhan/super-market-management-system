#include "Supplier.h"
#include "libraries.h"

Supplier::Supplier()
{
	category = NULL;
	company = NULL;
}

Supplier::Supplier( int age, char* name, char* gender, char* category, char* company, int ID, char* address, char* contact, double salary )
		 : Employee(age,name,gender,ID,address,contact,salary)
{
	this->category = new char[strlen(category) + 1];
	this->company = new char[strlen(company) + 1];
	strcpy(this->category,category);
	strcpy(this->company,company);
}

Supplier::~Supplier()
{
	delete [] category;
	delete [] company;
}

//			Setter Functions

void Supplier::setCategory( char* category )
{
	if(this->category == NULL)
	{
		if(category != NULL)
		{
			this->category = new char[strlen(category) + 1];
			strcpy(this->category,category);
		}
	}
	else if(category != NULL)
	{
		strcpy(this->category,category);
	}
}

void Supplier::setCompany( char* company )
{
	if(this->company == NULL)
	{
		if(company != NULL)
		{
			this->company = new char[strlen(company) + 1];
			strcpy(this->company,company);
		}
	}
	else if(company != NULL)
	{
		strcpy(this->company,company);
	}
}

//			Getter Functions

char* Supplier::getCategory() const
{
	return category;
}

char* Supplier::getCompany() const
{
	return company;
}

//			Other Functions

void Supplier::display() const
{
	Employee::display();
	std::cout << "CATEGORY: " << category << std::endl;
	std::cout << "COMPANY: " << category << std::endl;
}
