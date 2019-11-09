#include "Customer.h"
#include "libraries.h"

Customer::Customer()
{
	address = NULL;
	contact = NULL;
	account = new Account;
}

Customer::Customer( int accountNum, char* password, char* accountType, double balance, char* address, char* contact, int age, char* name, char* gender )
		  : Person(age,name,gender){
	this->address = new char[strlen(address) + 1];
	this->contact = new char[strlen(contact) + 1];
	account = new Account(accountNum,password,accountType,balance);
	strcpy(this->address,address);
	strcpy(this->contact,contact);
}

Customer::~Customer()
{
	delete [] address;
	delete [] contact;
	delete account;
}

//			Setter Functions

void Customer::setAddress( char* address )
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

void Customer::setContact( char* contact )
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

//			Getter Functions

char* Customer::getAddress() const
{
	return address;
}

char* Customer::getContact() const
{
	return contact;
}

//			Account Functions

void Customer::setNumber( int num )
{
	account->setNumber(num);
}

void Customer::setPassword( char* pass )
{
	account->setPassword(pass);
}

void Customer::setType( char* type )
{
	account->setType(type);
}

void Customer::setBalance( double balance )
{
	account->setBalance(balance);
}

void Customer::depositBalance( double balance )
{
	account->deposit(balance);
}

int Customer::getAccountNumber() const
{
	return account->getNumber();
}

char* Customer::getPassword() const
{
	return account->getPassword();
}

double Customer::getBalance() const
{
	return account->getBalance();
}

char* Customer::getType() const
{
	return account->getType();
}

void Customer::deductBalance( double bal )
{
	account->deductBalance(bal);
}

//			Other Functions

void Customer::createAccount()
{
	int num;
	char temp[50];
	bool flag = false;
	srand(time(0));
	num = rand() % 90000 + 10000;
	account->setNumber(num);
	
	fflush(stdin);
	system("cls");
	std::cout << "\n\t\tENTER DETAILS OF YOUR ACCOUNT\n";
	std::cout << "Enter your name: ";
	std::cin.getline(temp,50);
	Person::setName(temp);

	memset(temp,'\0',sizeof(temp));
	std::cout << "Enter your gender: ";
	std::cin >> temp;
	Person::setGender(temp);
	
	std::cout << "Enter your age: ";
	std::cin >> num;
	Person::setAge(num);
	
	while(!flag)
	{
		memset(temp,'\0',sizeof(temp));
		try{
			fflush(stdin);
			std::cout << "Enter your password: ";
			std::cin.getline(temp,100);
			if( strlen(temp) > 15 )
			throw 5;
			else if( strlen(temp) < 3 )
			throw 4;
			flag = true;
		}
		catch(int x){
			if(x == 4)
			std::cout << "Exception[" << x << "] " << "occured: PASSWORD TOO SHORT" << std::endl;
			else if(x == 5)
			std::cout << "Exception[" << x << "] " << "occured: PASSWORD TOO LONG" << std::endl;
		}
	}
	account->setPassword(temp);
	flag = false;
	while(!flag)
	{
		try{
			std::cout << "Enter account type\n ";
			std::cout << "\t1 for Regular Account \n";
			std::cout << "\t2 for Premium Account ";
			std::cout << "\n\t\tYour Choice: ";
			std::cin >> num;
			if(num != 1 && num != 2)
			throw 6;
			else if(num == 1)
			{
				memset(temp,'\0',sizeof(temp));
				strcpy(temp,"Regular");
			}
			else
			{
				memset(temp,'\0',sizeof(temp));
				strcpy(temp,"Premium");
			}
			flag = true;
		}
		catch(int x){
			std::cout << "Exception[" << x << "] " << "occured: INVALID ACCOUNT TYPE" << std::endl;
		}
	}
	account->setType(temp);
	
	fflush(stdin);
	memset(temp,'\0',sizeof(temp));
	std::cout << "Enter your address: ";
	std::cin.getline(temp,50);
	setAddress(temp);
	
	fflush(stdin);
	memset(temp,'\0',sizeof(temp));
	std::cout << "Enter your contact number: ";
	std::cin.getline(temp,50);
	setContact(temp);
	
	if(num == 1)
	account->setBalance(1000);
	else
	account->setBalance(5000);
	
	std::ofstream ofile;
	ofile.open("Customer.csv",std::ios_base::app);
	ofile << std::endl
		  << account->getNumber() << ","
		  << account->getPassword() << ","
		  << account->getType() << ","
		  << Person::getName() << ","
		  << Person::getGender() << ","
		  << Person::getAge() << ","
		  << account->getBalance() << ","
		  << address << "," << contact;
	ofile.close();
}

void Customer::removeAccount( char* acc )
{
	char temp[100], t[100];
	char* token;
	std::ifstream ifile;
	std::ofstream ofile;
	
	ifile.open("Customer.csv");
	int recordCount=0, copyCount=0;
	ifile.getline(temp,100);
	while(!ifile.eof())
	{
		ifile.getline(temp,100);
		recordCount++;
	}
	std::cout << recordCount;
	ifile.close();
	ifile.open("Customer.csv");
	ofile.open("temp.csv");
	ifile.getline(temp,100);
	ofile << temp << std::endl;
	int deleted=0;
	while(!ifile.eof())
	{
		memset(t,'\0',sizeof(t));
		ifile.getline(temp,100);
		copyCount++;
		strcpy(t,temp);
		token = strtok(t,",");
		if(strcmp(token,acc) != 0)
		{
			if(recordCount == copyCount+1 && !deleted)
			{
				ofile << temp;
				break;
			}
			if(recordCount == copyCount)
			ofile << temp;
			else
			ofile << temp << std::endl;
		}
		else
		deleted=1;
	}
	ofile.close();
	ifile.close();
	remove("Customer.csv");
	rename("temp.csv","Customer.csv");
}

void Customer::modifyAccount()
{
	char choice;
	char temp[100];
	std::cout << "\n\tENTER:\n\t\t1 to change name";
	std::cout << "\n\t\t2 to change password";
	std::cout << "\n\t\t3 to change age";
	std::cout << "\n\t\t4 to change address";
	std::cout << "\n\t\t5 to change contact";
	std::cout << "\n\t\t6 to deposit amount";
	std::cout << "\n\t\t7 to go back";
	std::cout << "\n\n\tYour Choice: ";
	std::cin >> choice;
	if(choice == '7')
	return;
	fflush(stdin);
	switch(choice)
	{
		case '1':
			std::cout << "\n\n\tEnter name to update: ";
			std::cin.getline(temp,100);
			setName(temp);
			break;
		case '2':
			std::cout << "\n\n\tEnter new password: ";
			std::cin.getline(temp,100);
			setPassword(temp);
			break;
		case '3':
			std::cout << "\n\n\tEnter age to update: ";
			std::cin.getline(temp,100);
			setAge(atoi(temp));
			break;
		case '4':
			std::cout << "\n\n\tEnter address to update: ";
			std::cin.getline(temp,100);
			setAddress(temp);
			break;
		case '5':
			std::cout << "\n\n\tEnter contact no. to update: ";
			std::cin.getline(temp,100);
			setContact(temp);
			break;
		case '6':
			std::cout << "\n\n\tEnter amount to be deposited: ";
			std::cin.getline(temp,100);
			depositBalance(atoi(temp));
			break;
	}
	char t[100];
	char* token;
	std::ifstream ifile;
	std::ofstream ofile;
	ifile.open("Customer.csv");
	int recordCount=0, copyCount=0;
	ifile.getline(temp,100);
	while(!ifile.eof())
	{
		ifile.getline(temp,100);
		recordCount++;
	}
	ifile.close();
	ifile.open("Customer.csv");
	ofile.open("temp.csv");
	while(!ifile.eof())
	{
		memset(t,'\0',sizeof(t));
		ifile.getline(temp,100);
		copyCount++;
		strcpy(t,temp);
		token = strtok(t,",");
		if(token == NULL) break;
//		if(strcmp(token,getAccountNumber()) == 0)
		if(atoi(token)==getAccountNumber())
		{
			token = strtok(temp,",");
			ofile << token << ",";
			if(choice == '1')
			{
				for(int i=0;i<2;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				ofile << getName() << ",";
				token = strtok(NULL,",");
				for(int i=0;i<4;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				token = strtok(NULL,"\0");
				if(recordCount+1 == copyCount)
				ofile << token;
				else
				ofile << token << std::endl;
			}
			else if(choice == '2')
			{
				ofile << getPassword() << ",";
				token = strtok(NULL,",");
				for(int i=0;i<6;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				token = strtok(NULL,"\0");
				if(recordCount+1 == copyCount)
				ofile << token;
				else
				ofile << token << std::endl;
			}
			else if(choice == '3')
			{
				for(int i=0;i<4;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				ofile << getAge() << ",";
				token = strtok(NULL,",");
				for(int i=0;i<2;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				token = strtok(NULL,"\0");
				if(recordCount+1 == copyCount)
				ofile << token;
				else
				ofile << token << std::endl;
			}
			else if(choice == '4')
			{
				for(int i=0;i<6;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				ofile << getAddress() << ",";
				token = strtok(NULL,",");
				token = strtok(NULL,"\0");
				if(recordCount+1 == copyCount)
				ofile << token;
				else
				ofile << token << std::endl;
			}
			else if(choice == '5')
			{
				for(int i=0;i<7;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				if(recordCount+1 == copyCount)
				ofile << getContact();
				else
				ofile << getContact() << std::endl;
			}
			else if(choice == '6')
			{
				for(int i=0;i<5;i++)
				{
					token = strtok(NULL,",");
					ofile << token << ",";
				}
				ofile << account->getBalance() << ",";
				token = strtok(NULL,",");
				token = strtok(NULL,",");
				ofile << token << ",";
				token = strtok(NULL,"\0");
				if(recordCount+1 == copyCount)
				ofile << token;
				else
				ofile << token << std::endl;
			}
		}
		else
		{
			if(recordCount+1 == copyCount )
			ofile << temp;
			else
			ofile << temp << std::endl;
		}
		if( copyCount > recordCount ) break;
	}
	ofile.close();
	ifile.close();
	remove("Customer.csv");
	rename("temp.csv","Customer.csv");
}

void Customer::display() const
{
	Person::display();
	std::cout << "ADDRESS: " << address << std::endl;
	std::cout << "CONTACT#: " << contact << std::endl;
	account->display();
}
