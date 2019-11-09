#include "Admin.h"
#include "libraries.h"
using namespace std;
Admin::Admin()
{
	ID = 0;
	password = NULL;
}

Admin::Admin( int ID, char* password, int age, char* name, char* gender )
	 : Person(age,name,gender){
	this->password = new char[strlen(password) + 1];
	strcpy(this->password,password);
	this->ID = ID;
}

Admin::~Admin()
{
	delete [] password;
}

void Admin::display() const
{
	std::cout << "ADMIN ID: " << ID << std::endl;
	Person::display();
}

		// Setter Functions

void Admin::setID( int ID )
{
	this->ID = ID;
}

void Admin::setPassword( char* password )
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

		// Getter Functions

int Admin::getID() const
{
	return ID;
}

char* Admin::getPassword() const
{
	return password;
}

		// Customer Handling

void Admin::addCustomer( Customer* custom, int& size )
{
	std::ifstream ifile;
	Customer* temp_custom;
	temp_custom = new Customer;
	temp_custom->createAccount();
	std::cout << "\n\t\tACCOUNT SUCCESSFULLY CREATED" << std::endl;
	std::cout << "Account number: " << temp_custom->getAccountNumber() << std::endl << std::endl;
	size++;
	delete temp_custom;
	delete custom;
	system("pause");
	char temp[100];
	ifile.open("Customer.csv");
	custom = new Customer[size];
	char* token;
	ifile.getline(temp,100);
	for(int i=0;i<size;i++)
	{
		memset(temp,'\0',sizeof(temp));
		ifile.getline(temp,100);
//		std::cout << temp;
//		getch();
		token=strtok(temp,",");
		custom[i].setNumber(atoi(token));
		token=strtok(NULL,",");
		custom[i].setPassword(token);
		token=strtok(NULL,",");
		custom[i].setType(token);
		token=strtok(NULL,",");
		custom[i].setName(token);
		token=strtok(NULL,",");
		custom[i].setGender(token);
		token=strtok(NULL,",");
		custom[i].setAge(atoi(token));
		token=strtok(NULL,",");
		custom[i].setBalance(atoi(token));
		token=strtok(NULL,",");
		custom[i].setAddress(token);
		token=strtok(NULL,"\0");
		custom[i].setContact(token);
	}
	ifile.close();
}

void Admin::deleteCustomer( Customer* custom, int& size )
{
	std::ifstream ifile;
	Customer* temp_custom;
	bool flag = false;
	char acc[10];
	std::cout << "\n\n\tEnter account number to delete: ";
	std::cin >> acc;
	char temp[100];
	ifile.open("Customer.csv");
	ifile.getline(temp,100);
	while(!ifile.eof())
	{
		char* token;
		ifile.getline(temp,100);
		token = strtok(temp,",");
		if(token == NULL)
		break;
		if(strcmp(token,acc) == 0)
		flag=1;
	}
	ifile.close();
	if(!flag)
	{
		std::cout << "\n\t\tACCOUNT DOESNOT EXIST" << std::endl;
		getch();
		return;
	}
	getch();
	temp_custom->removeAccount(acc);
	delete temp_custom;
	delete custom;
	size--;
	char* token;
	custom = new Customer[size];
	ifile.open("Customer.csv");
	ifile.getline(temp,100);
	for(int i=0;i<size;i++ )
	{
		memset(temp,'\0',sizeof(temp));
		ifile.getline(temp,100);
		token=strtok(temp,",");
		if(strcmp(token,acc)==0) continue;
		custom[i].setNumber(atoi(token));
		token=strtok(NULL,",");
		custom[i].setPassword(token);
		token=strtok(NULL,",");
		custom[i].setType(token);
		token=strtok(NULL,",");
		custom[i].setName(token);
		token=strtok(NULL,",");
		std::cout << token;
		getch();
		custom[i].setGender(token);
		token=strtok(NULL,",");
		custom[i].setAge(atoi(token));
		token=strtok(NULL,",");
		custom[i].setBalance(atoi(token));
		token=strtok(NULL,",");
		custom[i].setAddress(token);
		token=strtok(NULL,"\0");
		custom[i].setContact(token);
	}
	ifile.close();
}

void Admin::modifyCustomer( Customer* custom, int size )
{
	char acc[10];
	std::cout << "\n\n\tEnter account number to modify: ";
	std::cin >> acc;
	for(int i=0;i<size;i++)
	{
		if( atoi(acc) == custom[i].getAccountNumber() )
		{
			custom[i].modifyAccount();
			break;
		}
	}
}

void Admin::searchCustomer( Customer* custom, int size )
{
	char ID[10];
	std::cout << "\n\n\tEnter ID to search: ";
	std::cin >> ID;
	for(int i=0;i<size;i++)
	{
		if(custom[i].getAccountNumber()==atoi(ID))
		{
			std::cout << "\n\tACCOUNT DETAILS: " << std::endl;
			custom[i].display();
			getch();
			return;
		}
	}
	std::cout << "\nACCOUNT DOESNOT EXIST";
	getch();
}

void Admin::sortCustomer( Customer* custom, int size )
{
	char temp[100];
	int count=0;
	int i,record;
	system("cls");
	char choice;
	std::cout << "\n\tENTER to sort:\n\t\t1 by name";
	std::cout << "\n\t\t2 by gender";
	std::cout << "\n\t\t3 by age";
	std::cout << "\n\t\t4 by account no";
	std::cout << "\n\t\t5 by account type";
	std::cout << "\n\t\t6 to go back";
	std::cout << "\n\n\tYour Choice: ";
	std::cin >> choice;
	
	switch(choice){
		case '1':
			for(i=65; i<91;i++){
				for(int j=0; j<size; j++){
					strcpy(temp,custom[j].getName());
					strupr(temp);
					if((int)temp[0]==i){
					custom[j].display();
					system("pause");
					cout<<endl;
				}
				}
			}
			getch();
			break;
		
		case '2':
			char tempo[100];
			for(i=0; i<2; i++){
				for(int j=0; j<size; j++){
					strcpy(tempo,custom[j].getGender() );
					strupr(tempo);
					
					if(i==0 && !strcmp(tempo,"FEMALE") ){
						custom[j].display();
						system("pause");
						cout<<endl;
					}
					if(i==1 && !strcmp(tempo,"MALE") ){
						custom[j].display();
						system("pause");
						cout<<endl;
					}
				}
			}
			getch();
			break;
			
		case '3':
			i=0; record=0;
			while(1){
				for(int j=0; j<size; j++){
					if(custom[j].getAge()==i){
						custom[j].display();
						system("pause");
						cout<<endl;
						record++;
					}
				}
				i++;
					if(size==record){
						getch();
						break;
					}
			}
			getch();
			break;
				
		case '4':
			record=0;
			for(i=9999; 1 ; i++){
				for(int j=0; j<size; j++){
					int ptr=custom[j].getAccountNumber();
					if(ptr==i){
						custom[j].display();
						system("pause");
						cout<<endl;
						record++;
					}
				}
					if(size==record){
						getch();
						break;
					}
			}
			getch();
			break;
			
		case '5':
			for(i=0; i<2; i++){
				for(int j=0; j<size; j++){
					strcpy(tempo,custom[j].getType() );
					strupr(tempo);
					
					if(i==0 && !strcmp(tempo,"REGULAR") ){
						custom[j].display();
						system("pause");
						cout<<endl;
					}
					if(i==1 && !strcmp(tempo,"PREMIUM") ){
						custom[j].display();
						system("pause");
						cout<<endl;
					}
				}
			}
			getch();
			break;
		
		case '6':
			break;	
	}
}
		// Employee Handling
		
void Admin::addEmployee( Employee* employ, int& size )
{
	system("cls");
 	Worker* work_temp = new Worker;
	int num;
	char temp[100];
	srand(time(0));
	num = rand() % 90000 + 10000;
	work_temp->setID(num);
	std::cout << "\n\t\tENTER DETAILS OF EMPLOYEE\n";
	fflush(stdin);
	std::cout << "Enter your name: ";
	std::cin.getline(temp,50);
	work_temp->setName(temp);
	
	memset(temp,'\0',sizeof(temp));
	fflush(stdin);
	std::cout << "Enter gender: ";
	std::cin >> temp;
	work_temp->setGender(temp);
	
	std::cout << "Enter age: ";
	std::cin >> num;
	work_temp->setAge(num);
	
	std::cout << "Enter salary: ";
	std::cin >> num;
	work_temp->setSalary(num);
	
	std::cout << "Enter year of joining: ";
	std::cin >> num;
	work_temp->setYear(num);
	
	fflush(stdin);
	std::cout << "Enter address: ";
	memset(temp,'\0',sizeof(temp));
	std::cin.getline(temp,100);
	work_temp->setAddress(temp);
	
	fflush(stdin);
	std::cout << "Enter contact: ";
	memset(temp,'\0',sizeof(temp));
	std::cin.getline(temp,100);
	work_temp->setContact(temp);
	work_temp->setLeave(false);
	
	std::ifstream ifile;
	std::ofstream ofile;
	ofile.open("Worker.csv",std::ios_base::app);
	ofile << std::endl
		  << work_temp->getID() << ","
		  << work_temp->getName() << ","
		  << work_temp->getAge() << ","
		  << work_temp->getGender() << ","
		  << work_temp->getSalary() << ","
		  << "Worker,"
		  << work_temp->getYear() << ","
		  << work_temp->getAddress() << ","
		  << work_temp->getContact() << ","
		  << "Active";
	ofile.close();
	std::cout << "\n\t\tRECORD SUCCESSFULLY CREATED" << std::endl;
	std::cout << "Employee ID: " << work_temp->getID() << std::endl;
	system("pause");
	size++;
	work_temp = NULL;
	employ = NULL;
	getch();
	memset(temp,'\0',sizeof(temp));
	char* token;
	employ = new Worker[size];
	ifile.open("Worker.csv");
	ifile.getline(temp,100);
	for(int i=0;i<size;i++)
	{
		memset(temp,'\0',sizeof(temp));
		ifile.getline(temp,100);
		token=strtok(temp,",");
		employ[i].setID(atoi(token));
		token=strtok(NULL,",");
		employ[i].setName(token);
		token=strtok(NULL,",");
		employ[i].setAge(atoi(token));
		token=strtok(NULL,",");
		employ[i].setGender(token);
		token=strtok(NULL,",");
		employ[i].setSalary(atoi(token));
		token=strtok(NULL,",");
		token=strtok(NULL,",");
		work_temp = (Worker*) &(employ[i]);
		work_temp->setYear(atoi(token));
//		employ[i].setYear(atoi(token));
		token=strtok(NULL,",");
		employ[i].setAddress(token);
		token=strtok(NULL,",");
		employ[i].setContact(token);
		token=strtok(NULL,"\0");
		if(strcmp(token,"Active")==0)
		employ[i].setLeave(false);
		else
		employ[i].setLeave(true);
	}
	ifile.close();
}

void Admin::deleteEmployee( Employee* employ, int& size )
{
	char temp[100], acc[10];
	std::cout << "Enter ID to delete: ";
	std::cin >> acc[10];
	std::ifstream ifile;
	std::ofstream ofile;
	ofile.open("temp.csv");
	ifile.open("Worker.csv");
	ifile.getline(temp,100);
	ofile << temp;
	for(int i=0;i<size;i++)
	{
		ifile.getline(temp,100);
		char* token=strtok(temp,",");
		if(strcmp(token,acc)==0)
		continue;
		else
		ofile << temp << endl;
	}
	std::cout << "\n\t\tRECORD SUCCESSFULLY DELETED" << std::endl;
	size--;
	delete employ;
	ofile.close();
	ifile.close();
//	work_temp = NULL;
	Worker* work_temp= new Worker[size+1];
	employ = NULL;
	getch();
	memset(temp,'\0',sizeof(temp));
	char* token;
	employ = new Worker[size];
	ifile.open("Worker.csv");
	ifile.getline(temp,100);
	for(int i=0;i<size;i++)
	{
		memset(temp,'\0',sizeof(temp));
		ifile.getline(temp,100);
		token=strtok(temp,",");
		employ[i].setID(atoi(token));
		token=strtok(NULL,",");
		employ[i].setName(token);
		token=strtok(NULL,",");
		employ[i].setAge(atoi(token));
		token=strtok(NULL,",");
		employ[i].setGender(token);
		token=strtok(NULL,",");
		employ[i].setSalary(atoi(token));
		token=strtok(NULL,",");
		token=strtok(NULL,",");
		work_temp = (Worker*) &(employ[i]);
		work_temp->setYear(atoi(token));
//		employ[i].setYear(atoi(token));
		token=strtok(NULL,",");
		employ[i].setAddress(token);
		token=strtok(NULL,",");
		employ[i].setContact(token);
		token=strtok(NULL,"\0");
		if(strcmp(token,"Active")==0)
		employ[i].setLeave(false);
		else
		employ[i].setLeave(true);
	}
	delete [] work_temp;
	ifile.close();
}

void Admin::searchEmployee( Employee* employ, int size )
{
	char ID[10];
	std::cout << "\n\n\tEnter ID to search: ";
	std::cin >> ID;
	for(int i=0;i<size;i++)
	{
		if(employ[i].getID()==atoi(ID))
		{
			std::cout << "\n\tEMPLOYEE DETAILS: " << std::endl;
			employ[i].display();
			getch();
			return;
		}
	}
	std::cout << "\nRECORD DOESNOT EXIST";
	getch();
}
