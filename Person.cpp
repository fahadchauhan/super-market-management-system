#include "Person.h"
#include "libraries.h"

Person::Person()
{
	age = 0;
	name = NULL;
	gender = NULL;
}

Person::Person( int age, char* name, char* gender )
{
	this->age = age;
	this->name = new char[strlen(name) + 1];
	this->gender = new char[strlen(gender) + 1];
	strcpy(this->name, name);
	strcpy(this->gender, gender);
}

Person::~Person()
{
	delete [] name;
	delete [] gender;
}

//			Setter Functions

void Person::setAge( int age )
{
	while(age < 0)
	{
		try{
			if(age < 0)
			throw 1;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: AGE CANNOT BE NEGATIVE" << std::endl;
			std::cout << "\tEnter valid age: ";
			std::cin >> age;
		}
	}
	this->age = age;
}

void Person::setName( char *name )
{
	if(this->name == NULL)
	{
		if(name != NULL)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
	}
	else if(name != NULL)
	{
		strcpy(this->name, name);
	}
}

void Person::setGender( char *gender )
{
	if(this->gender == NULL)
	{
		if(gender != NULL)
		{
			this->gender = new char[strlen(gender) + 1];
			bool flag = false;
			while(!flag)
			{
				char temp[10];
				strcpy(temp,gender);
				strupr(temp);
				try{
					if(strcmp(temp,"MALE") != 0 && strcmp(temp,"FEMALE") != 0)
					throw 2;
					flag = true;
				}
				catch(int x){
					std::cout << "Exception[" << x << "] " << "occured: INVALID GENDER" << std::endl;
					std::cout << "\tEnter valid gender: ";
					std::cin >> gender;
				}
			}
			strcpy(this->gender,gender);
		}
	}
	else if(gender != NULL)
	{
		bool flag = false;
		while(!flag)
		{
			char temp[10];
			strcpy(temp,gender);
			strupr(temp);
			try{
				if(strcmp(temp,"MALE") != 0 && strcmp(temp,"FEMALE") != 0)
				throw 2;
				flag = true;
			}
			catch(int x){
				std::cout << "Exception[" << x << "] " << "occured: INVALID GENDER" << std::endl;
				std::cout << "\tEnter valid gender: ";
				std::cin >> gender;
			}
		}
		strcpy(this->gender, gender);
	}
}

//			Getter Functions

int Person::getAge() const
{
	return age;
}

char * Person::getName() const
{
	return name;
}

char * Person::getGender() const
{
	return gender;
}

//			Other Functions

void Person::display() const
{
//	if( age != 0 )
	std::cout << "AGE: " << age << std::endl;
//	if( name != NULL )
	std::cout << "NAME: " << name << std::endl;
//	if( gender != NULL )
	std::cout << "GENDER: " << gender << std::endl;
}
