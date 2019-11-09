#include "ATM.h"
#include "libraries.h"

//			Setter Functions

void ATM::setNum( int num )
{
	account_num = num;
}

void ATM::setPIN( int PIN )
{
	this->PIN = PIN;
}

void ATM::setBalance( double balance )
{
	this->balance = balance;
}

//			Getter Functions

int ATM::getNum() const
{
	return account_num;
}

int ATM::getPIN() const
{
	return PIN;
}

//			Other Functions

void ATM::withDraw()
{
	double amount;
	std::cout << "\n\n\t\t\t\tATM MACHINE\n\t\t";
	for(int i=0; i<50; i++)
	std::cout << "=";
	std::cout << std::endl << std::endl << std::setw(20) << " " << "Enter amount to withdraw: ";
	std::cin >> amount;
	while(amount < 0)
	{
		try{
			if(amount < 0)
			throw 3;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: NEGATIVE BALANCE ENTERED" << std::endl;
			std::cout << "\tEnter valid amount: " << std::endl;
			std::cin >> amount;
		}
	}
	if(amount > balance)
	{
		std::cout << "INSUFFICIENT BALANCE";
		getch();
		return;
	}
	balance -= amount;
	std::cout << std::endl << std::endl << std::setw(20) << " " << "AMOUNT SUCCESSFULLY WITHDRAWN";
	std::ifstream ifile;
	std::ofstream ofile;
	ifile.open("ATM.csv");
	ofile.open("temp.csv");
	char temp[50], *token;
	ifile.getline(temp,50);
	ofile << temp << std::endl;
	while(!ifile.eof())
	{
		ifile.getline(temp,50);
		token = strtok(temp,",");
		if(atoi(token)==account_num)
		{
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << ",";
			ofile << balance << std::endl;
		}
		else
		{
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << "," << std::endl;
		}
	}
	ifile.close();
	ofile.close();
	remove("ATM.csv");
	rename("temp.csv","ATM.csv");
	getch();
}

void ATM::withDraw( double amount )
{
	while(amount < 0)
	{
		try{
			if(amount < 0)
			throw 3;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: NEGATIVE BALANCE ENTERED" << std::endl;
			std::cout << "\tEnter valid amount: " << std::endl;
			std::cin >> amount;
		}
	}
	if(amount > balance)
	{
		std::cout << "INSUFFICIENT BALANCE";
		getch();
		return;
	}
	balance -= amount;
	std::cout << std::endl << std::endl << std::setw(20) << " " << "AMOUNT SUCCESSFULLY WITHDRAWN";
	std::ifstream ifile;
	std::ofstream ofile;
	ifile.open("ATM.csv");
	ofile.open("temp.csv");
	char temp[50], *token;
	ifile.getline(temp,50);
	ofile << temp << std::endl;
	while(!ifile.eof())
	{
		ifile.getline(temp,50);
		token = strtok(temp,",");
		if(atoi(token)==account_num)
		{
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << ",";
			ofile << balance << std::endl;
		}
		else
		{
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << "," << std::endl;
		}
	}
	ifile.close();
	ofile.close();
	remove("ATM.csv");
	rename("temp.csv","ATM.csv");
	getch();
}

void ATM::deposit()
{
	double amount;
	std::cout << "\n\n\t\t\t\tATM MACHINE\n\t\t";
	for(int i=0; i<50; i++)
	std::cout << "=";
	std::cout << std::endl << std::endl << std::setw(20) << " " << "Enter amount to deposit: ";
	std::cin >> amount;
	while(amount < 0)
	{
		try{
			if(amount < 0)
			throw 3;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: NEGATIVE BALANCE ENTERED" << std::endl;
			std::cout << "\tEnter valid amount: " << std::endl;
			std::cin >> amount;
		}
	}
	balance += amount;
	std::cout << std::endl << std::endl << std::setw(20) << " " << "AMOUNT SUCCESSFULLY DEPOSITED";
	std::ifstream ifile;
	std::ofstream ofile;
	ifile.open("ATM.csv");
	ofile.open("temp.csv");
	char temp[50], *token;
	ifile.getline(temp,50);
	ofile << temp << std::endl;
	while(!ifile.eof())
	{
		ifile.getline(temp,50);
		token = strtok(temp,",");
		if(atoi(token)==account_num)
		{
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << ",";
			ofile << balance << std::endl;
		}
		else
		{
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << ",";
			token = strtok(NULL,",");
			ofile << token << "," << std::endl;
		}
	}
	ifile.close();
	ofile.close();
	remove("ATM.csv");
	rename("temp.csv","ATM.csv");
	getch();
}

void ATM::details() const
{
	std::cout << "ACCOUNT NUMBER: " << account_num << std::endl;
	std::cout << "CURRENT BALANCE: $" << balance << std::endl;
}
