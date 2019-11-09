#include "Account.h"
#include "libraries.h"

Account::Account()
{
	account_num = 0;
	type = NULL;
	password = NULL;
	balance = 0;
}

Account::Account( int num, char* password, char* type, double balance )
{
	account_num = num;
	this->balance = balance;
	this->password = new char[strlen(password) + 1];
	this->type = new char[strlen(type) + 1];
	strcpy(this->password,password);
	strcpy(this->type,type);
}

Account::~Account()
{
	delete [] password;
	delete [] type;
}

//			Setter Functions

void Account::setNumber( int number )
{
	account_num = number;
}

void Account::setPassword( char* password )
{
	if(this->password == NULL)
	{
		if(password != NULL)
		{
			this->password = new char[strlen(password) + 1];
			strcpy(this->password,password);
		}
	}
	else if(password != NULL)
	{
		strcpy(this->password,password);
	}
}

void Account::setType( char* type )
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

void Account::setBalance( double balance )
{
	while(balance < 0)
	{
		try{
			if(balance < 0)
			throw 3;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: NEGATIVE BALANCE ENTERED" << std::endl;
			std::cout << "\tEnter valid balance: " << std::endl;
			std::cin >> balance;
		}
	}
	this->balance = balance;
}

//			Getter Functions

int Account::getNumber() const
{
	return account_num;
}

char* Account::getPassword() const
{
	return password;
}

char* Account::getType() const
{
	return type;
}

double Account::getBalance() const
{
	return balance;
}

//			Other Functions

void Account::deposit( double balance )
{
	while( balance < 0 )
	{
		try{
			if( balance < 0 )
			throw 3;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: NEGATIVE BALANCE ENTERED" << std::endl;
			std::cout << "\tEnter valid balance: ";
			std::cin >> balance;
		}
	}
	this->balance += balance;
}

void Account::deductBalance( double balance )
{
	if( balance > this->balance )
	std::cout << "\t\tINSUFFICIENT BALANCE" << std::endl;
	else
	this->balance -= balance;
}

void Account::display() const
{
	std::cout << "ACCOUNT NO: " << account_num << std::endl;
	std::cout << "ACCOUNT TYPE: " << type << std::endl;
	std::cout << "BALANCE: $" << balance << std::endl;
}
