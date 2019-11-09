#include "Item.h"
#include "libraries.h"

Item::Item()
{
	name = NULL;
	type = NULL;
	price = 0;
	quantity = 0;
}

Item::Item( char* name, char* type, double price, int quantity )
{
	this->name = new char[strlen(name) + 1];
	this->type = new char[strlen(type) + 1];
	strcpy(this->name,name);
	strcpy(this->type,type);
	this->price = price;
	this->quantity = quantity;
}

Item::~Item()
{
	delete [] name;
	delete [] type;
}

//		Setter Functions

void Item::setName( char* name )
{
	if(this->name == NULL)
	{
		if(name != NULL)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name,name);
		}
	}
	else if(name != NULL)
	{
		strcpy(this->name,name);
	}
}

void Item::setType( char* type )
{
	if(this->type == NULL)
	{
		if(type != NULL)
		{
			this->type = new char[strlen(type) + 1];
			strcpy(this->type,type);
		}
	}
	else if(type != NULL)
	{
		strcpy(this->type,type);
	}
}

void Item::setPrice( double price )
{
	this->price = price;
}

void Item::setQuantity( int quantity )
{
	this->quantity = quantity;
}

		// Getter Functions

char* Item::getName()
{
	return name;
}

char* Item::getType()
{
	return type;
}

double Item::getPrice()
{
	return price;
}

int Item::getQuantity()
{
	return quantity;
}

		// Other Functions
		
void Item::display() const
{
	std::cout << "PRODUCT NAME: " << name << std::endl;
	std::cout << "PRODUCT TYPE: " << type << std::endl;
	std::cout << "PRODUCT PRICE: " << price << std::endl;
	std::cout << "PRODUCT QUANTITY: " << quantity << std::endl;
}
