#include "libraries.h"
#include "CustomerInventory.h"
#include "AdminInventory.h"
#include "ATM.h"
#include "Account.h"
#include "Person.h"
#include "Admin.h"
#include "Customer.h"
#include "Employee.h"
#include "Supplier.h"
#include "Worker.h"
#include "Cashier.h"
#include "Guard.h"
#include "Wallet_Parking.h"
#include "Item.h"
#include "ShoppingCart.h"

COORD coord = {0, 0};
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool customerLogged = false;
bool ATM_used = false;

std::string hidePass();
void GUI();
void loading();
void gotoxy(int,int);
void menuDisplay();
int checkAccount(char*);
int checkAdmin(char*);
int validCode();
void quit();
void payInfo();

int main(int argc, char** argv) {
	GUI();
	char choice = '1';
	Admin* admin = NULL;
	int adminFlag;

	Customer* custom = NULL;
	char acc[10];
	int accountFlag;
	
	std::ifstream ifile;
	Worker* worker = NULL;
	
	Item* item = NULL;
	
	double bill = 0;
	bool billDue = false;
	
	while(1)
	{
		system("cls");
		system("color F0");
		menuDisplay();
		choice = getche();
		Sleep(500);
		switch(choice)
		{
			case '1':
				while(1)
				{
//					int quantity;
					ShoppingCart cart;
					std::ifstream iifile;
					CustomerInventory custom_inv;
					system("cls");
					if(customerLogged)
					{
						gotoxy(5,20);
						std::cout << "Welcome, " << custom->getName() << "!";
						if(bill != 0)
						std::cout << "\t\t\t     Your Bill is: $" << bill;
						gotoxy(25,0);
					}
					custom_inv.customerDisplay();
					choice = getch();
//					Sleep(500);
					switch(choice)
					{
						case '1':
							custom_inv.itemDisplay();
							choice = getch();
//							Sleep(500);
							char tem[100];
							char* tokenn;
							int num;
							item = new Item[20];
							switch(choice)
							{
								case '1':
									custom_inv.clothesDisplay();
									choice = getch();
									switch(choice)
									{
										case '1':
											iifile.open("Men.csv");
											break;
										case '2':
											iifile.open("Women.csv");
											break;
										case '3':
											iifile.open("Perfumes.csv");
											break;
										case '4':
											iifile.open("Shoes.csv");
											break;
										case '5':
											break;
									}
									if(choice == '5') break;
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
								case '2':
									custom_inv.electricDisplay();
									choice = getch();
									switch(choice)
									{
										case '1':
											iifile.open("Fridge.csv");
											break;
										case '2':
											iifile.open("AC.csv");
											break;
										case '3':
											iifile.open("LED.csv");
											break;
										case '4':
											iifile.open("Microwave.csv");
											break;
										case '5':
											iifile.open("Washing machine.csv");
											break;
									}
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
								case '3':
									custom_inv.foodDisplay();
									choice = getch();
									switch(choice)
									{
										case '1':
											iifile.open("Chips.csv");
											break;
										case '2':
											iifile.open("Chocolates.csv");
											break;
										case '3':
											iifile.open("Biscuits.csv");
											break;
										case '4':
											iifile.open("Drinks.csv");
											break;
									}
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
								case '4':
									custom_inv.groceryDisplay();
									choice = getch();
									switch(choice)
									{
										case '1':
											iifile.open("Fruits.csv");
											break;
										case '2':
											iifile.open("Vegetables.csv");
											break;
										case '3':
											iifile.open("Dairy.csv");
											break;
										case '4':
											iifile.open("Bakery.csv");
											break;
										case '5':
											iifile.open("Cereals.csv");
											break;
										case '6':
											iifile.open("Frozen Items.csv");
											break;
									}
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
								case '5':
									iifile.open("Medicines.csv");
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
								case '6':
									iifile.open("Furniture.csv");
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
								case '7':
									iifile.open("Sports.csv");
									iifile.getline(tem,100);
									for(int i=0;i<20;i++)
									{
										memset(tem,'\0',sizeof(tem));
										iifile.getline(tem,100);
										tokenn=strtok(tem,",");
										item[i].setName(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setType(tokenn);
										tokenn=strtok(NULL,",");
										item[i].setQuantity(atoi(tokenn));
										tokenn=strtok(NULL,"\0");
										item[i].setPrice(atoi(tokenn));
									}
									iifile.close();
									system("cls");
									for(int i=0;i<20;i++)
									{
										std::cout << "\n   " << i+1 << ".    " << item[i].getName() << " " << std::setw(40) << item[i].getPrice();
									}
									std::cout << "\n\n\tYour Choice: ";
									std::cin >> num;
									bill += item[num-1].getPrice();
									cart.addItem(item[num-1]);
									break;
							}
							if(choice != '5')
							printf( "\t\t\t    Item added to your cart" );
							getch();
							delete [] item;
							break;
						case '2':
							system("cls");
							custom_inv.accountDisplay();
							choice = getche();
							Sleep(500);
							switch(choice)
							{
								case '1':
								if(customerLogged)
								{
									std::cout << "\n\n\t\t     Account already logged in!";
									getch();
									break;
								}
								std::cout << "\n\n\t\t     Do you already have an account? (Y/N)";
								std::cout << "\n\t\t\t       Your Choice: ";
								std::cin >> choice;
								if( choice == 'Y' || choice == 'y' )
								{
									std::cout << std::endl << std::endl << std::setw(20) << " " << "\tEnter account number: ";
									std::cin >> acc;
									accountFlag = checkAccount(acc);
									if(accountFlag == 1)
									{
										loading();
										std::cout << "\n\n\t\t       ACCOUNT SUCCESSFULLY LOGGED IN";
										customerLogged = true;
										getch();
										char temp[100];
										std::ifstream ifile;
										ifile.open("Customer.csv");
										ifile.getline(temp,100);
										while(1)
										{
											memset(temp,'\0',sizeof(temp));
											ifile.getline(temp,100);
											char* token;
											token = strtok(temp,",");
											if( strcmp(token,acc) == 0 )
											{
												custom = new Customer;
												custom->setNumber(atoi(token));
												token = strtok(NULL,",");
												custom->setPassword(token);
												token = strtok(NULL,",");
												custom->setType(token);
												token = strtok(NULL,",");
												custom->setName(token);
												token = strtok(NULL,",");
												custom->setGender(token);
												token = strtok(NULL,",");
												custom->setAge(atoi(token));
												token = strtok(NULL,",");
												custom->setBalance(atoi(token));
												token = strtok(NULL,",");
												custom->setAddress(token);
												token = strtok(NULL,"\0");
												custom->setContact(token);
												break;
											}
										}
									}
									else if(accountFlag == 0)
									{
										std::cout << "\n\n\t\t       SORRY, ACCOUNT DOESNOT EXIST";
										std::cout << "\n\n\t\t Would you like to create a new account? (Y/N)";
										std::cout << "\n\t\t\t       Your Choice: ";
										std::cin >> choice;
										if( choice == 'Y' || choice == 'y' )
										{
											custom = new Customer;
											custom->createAccount();
											loading();
											std::cout << "\n\t\tACCOUNT SUCCESSFULLY CREATED" << std::endl;
											std::cout << "Please note your account number: " << custom->getAccountNumber() << std::endl << std::endl;
											system("pause");
											customerLogged = true;
										}
									}
									else if(accountFlag == -1)
									{
										std::cout << "\n\n\t\t         WRONG PASSWORD ENTERED";
										getch();
									}
								}
								else
								{
									std::cout << "\n\n\t\t Would you like to create a new account? (Y/N)";
									std::cout << "\n\t\t\t       Your Choice: ";
									std::cin >> choice;
									if( choice == 'Y' || choice == 'y' )
									{
										custom = new Customer;
										custom->createAccount();
										loading();
										std::cout << "\n\n\t\t\tACCOUNT SUCCESSFULLY CREATED" << std::endl;
										std::cout << "Please note your account number: " << custom->getAccountNumber() << std::endl << std::endl;
										system("pause");
										customerLogged = true;
									}
								}
								break;
								case '2':
								std::cout << std::endl << std::endl << std::setw(20) << " " << "\tEnter account number: ";
								std::cin >> acc;
								accountFlag = checkAccount(acc);
								if(accountFlag == 0)
								{
									std::cout << "\n\n\t\t       SORRY, ACCOUNT DOESNOT EXIST";
									getch();
								}
								else if(accountFlag == -1)
								{
									std::cout << "\n\n\t\t         WRONG PASSWORD ENTERED";
									getch();
								}
								else
								{
									std::cin.ignore();
									std::cout << "\n\n\t\tAre you sure you want to delete your account? (Y/N): ";
									std::cin >> choice;
									if( choice == 'y' || choice == 'Y' )
									{
										Customer temp;
										temp.removeAccount(acc);
										loading();
										std::cout << "\n\n\t\t\tACCOUNT SUCCESSFULLY DELETED" << std::endl;
										getch();
									}
								}
								break;
								case '3':
								if(!customerLogged)
								{
									std::cout << std::endl << std::endl << "\t\t   YOU NEED TO LOG INTO YOUR ACCOUNT FIRST!";
									getch();
									break;
								}
								system("cls");
								custom->modifyAccount();
								loading();
								std::cout << "\n\n\t\t\tACCOUNT SUCCESSFULLY UPDATED" << std::endl;
								getch();
								break;
								case '4':
								if(!customerLogged)
								{
									std::cout << std::endl << std::endl << "\t\t   YOU NEED TO LOG INTO YOUR ACCOUNT FIRST!";
									getch();
									break;
								}
								system("cls");
								std::cout << "\n\tACCOUNT DETAILS: " << std::endl;
								custom->display();
								getch();
								break;
							}
							break;
						case '3':
							char temp[50], match[10];
							int flag;
							flag = 0;
							char* token;
							ATM* atm;
							std::cout << "\n\nEnter account number: ";
							std::cin >> match;
							iifile.open("ATM.csv");
							iifile.getline(temp,50);
							while(!iifile.eof())
							{
								iifile.getline(temp,50);
								token = strtok(temp,",");
								if(token == NULL) break;
								if( strcmp(token,match)==0)
								{
									atm = new ATM;
									atm->setNum(atoi(token));
									token = strtok(NULL,",");
									atm->setPIN(atoi(token));
									token = strtok(NULL,"\0");
									atm->setBalance(atoi(token));
									flag=1;
									break;
								}
							}
							iifile.close();
							atm->details();
							getch();
							if(!flag)
							{
								std::cout << "ACCOUNT DOESNOT EXIST";
								getch();
								break;
							}
							system("cls");
							std::cout << "\n\n\t\t\t\tATM MACHINE\n\t\t";
							for(int i=0; i<50; i++)
							std::cout << "=";
							std::cout << "\n\n\t\t\tENTER\n\t1 to deposit";
							std::cout << "\n\t2 to withdraw";
							std::cout << "\n\t\tYour Choice: ";
							std::cin >> choice;
							if(choice == '1')
							atm->deposit();
							else if(choice == '2')
							atm->withDraw();
							ATM_used = true;
							delete atm;
							break;
						case '4':
							if(bill == 0 ){
							std::cout << "\n\n\t\t    Are you sure you want to exit? (Y/N): ";
							std::cin >> choice;
							if( choice == 'y' || choice == 'Y' )
							{
								system( "color 0F" );
								quit();
								if(custom != NULL)
								delete custom;
								return 0;
							}
							break;
						  }
						  else while(1){
						  	system("cls");
						  	char choice;
						  	std::cout << "\n\t\t\tYour bill is:  $" << bill;
						  	std::cout << "\n\n\t\t\tHow would you like to pay? ";
						  	std::cout << "\n\t\t\t1. Through Cash";
						  	std::cout << "\n\t\t\t2. Through Account";
						  	std::cout << "\n\t\t\t3. Through Card";
						  	std::cout << "\n\t\t\t4. Pay Info";
						  	std::cout << "\n\n\t\t\tYour Choice: ";
						  	std::cin >> choice;
						  	switch(choice)
						  	{
						  		case '1':
						  			if( bill > 50000 && !ATM_used ){
						  				std::cout << "\n\n\t\tSorry, you cannot pay a huge amount through cash";
						  				std::cout << "\n\t\tWould you like to use the ATM? (Y or N): ";
						  				std::cin >> choice;
						  				if(choice == 'y'||choice == 'Y')
						  				{
						  					char temp[50], match[10];
											int flag;
											flag = 0;
											char* token;
											ATM* atm;
											std::cout << "\n\nEnter account number: ";
											std::cin >> match;
											iifile.open("ATM.csv");
											iifile.getline(temp,50);
											while(!iifile.eof())
											{
												iifile.getline(temp,50);
												token = strtok(temp,",");
												if(token == NULL) break;
												if( strcmp(token,match)==0)
												{
													atm = new ATM;
													atm->setNum(atoi(token));
													token = strtok(NULL,",");
													atm->setPIN(atoi(token));
													token = strtok(NULL,"\0");
													atm->setBalance(atoi(token));
													flag=1;
													break;
												}
											}
											iifile.close();
											atm->details();
											getch();
											if(!flag)
											{
												std::cout << "\t\tACCOUNT DOESNOT EXIST";
												getch();
												break;
											}
											atm->withDraw(bill);
											delete atm;
										}
									}
									else{
										std::cout << "\n\t\tBILL SUCCESSFULLY PAID";
										quit();
										if(custom != NULL)
										delete custom;
										return 0;
									}
									break;
								case '2':
									if(!customerLogged)
									{
										std::cout << "\n\t\tONLY VALUED CUSTOMERS CAN AVAIL THIS OFFER";
										getch();
										break;
									}
									else
									{
										custom->deductBalance(bill);
										char tempp[100]; char matchh[50]; char* tok;
										std::cout << "\n\t\tBILL SUCCESSFULLY PAID";
										std::ifstream ifilee;
										std::ofstream ofilee;
										ifilee.open("Customer.csv");
										ofilee.open("temp.csv");
										ifilee.getline(tempp,100);
										ofilee << tempp << std::endl;
										while(!ifilee.eof())
										{
											ifilee.getline(tempp,100);
											strcpy(matchh,temp);
											tok=strtok(matchh,",");
											if(tok == NULL) break;
											if(atoi(tok)==custom->getAccountNumber())
											{
												ofilee << token;
												for(int i=0;i<5;i++)
												{
													tok=strtok(NULL,",");
													ofilee << token;
												}
												ofilee << custom->getBalance();
												tok=strtok(NULL,",");
												tok=strtok(NULL,",");
												ofilee << token;
												tok=strtok(NULL,"\0");
												ofilee << tok << std::endl;
											}
											else
											ofilee << tempp << std::endl;
										}
										
										quit();
										if(custom != NULL)
										delete custom;
										return 0;
									}
									break;
						  		case '3':
						  			int valid;
						  			valid = validCode();
						  			if( valid ){
						  				system( "color 0F" );
										quit();
										if(custom != NULL)
										delete custom;
										return 0;
									}
									else{
										std::cout << "\t\tINVALID CARD";
										getch();
										break;
									}
								case '4':
									payInfo();
									break;
							}
						}
					}
				}
				break;
			case '2':
				std::cout << "\n\n\t\t\t   Enter admin ID:  ";
				std::cin >> acc;
				adminFlag = checkAdmin(acc);
				if(adminFlag == -1)
				{
					std::cout << "\n\n\t\t\t    WRONG PASSWORD ENTERED";
					getch();
					break;
				}
				else if(adminFlag == 0)
				{
					std::cout << "\n\n\t\t\t      INVALID ID ENTERED";
					getch();
					break;
				}
				loading();
				std::cout << "\n\n\t\t       ACCOUNT SUCCESSFULLY LOGGED IN";
				AdminInventory admin_inv;
				getch();
				char temp[100];
				ifile.open("Admin.txt");
				admin = new Admin;
				ifile.getline(temp,100);
				admin->setName(temp);
				ifile.getline(temp,100);
				admin->setAge(atoi(temp));
				ifile.getline(temp,100);
				admin->setGender(temp);
				ifile.getline(temp,100);
				admin->setID(atoi(temp));
				ifile.getline(temp,100);
				admin->setPassword(temp);
				ifile.close();
				int customerRecord, workerRecord;
				memset(temp,'\0',sizeof(temp));
				customerRecord=0;
				ifile.open("Customer.csv");
				ifile.getline(temp,100);
				while(!ifile.eof())
				{
					ifile.getline(temp,100);
					if(strcmp(temp,"")==0)
					break;
					customerRecord++;
				}
				ifile.close();
				ifile.open("Customer.csv");
//				Customer* custom;
				custom = new Customer[customerRecord];
				char* token;
				ifile.getline(temp,100);
				for(int i=0;i<customerRecord;i++)
				{
					memset(temp,'\0',sizeof(temp));
					ifile.getline(temp,100);
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
				
				memset(temp,'\0',sizeof(temp));
				workerRecord=0;
				ifile.open("Worker.csv");
				ifile.getline(temp,100);
				while(!ifile.eof())
				{
					ifile.getline(temp,100);
					if(strcmp(temp,"")==0)
					break;
					workerRecord++;
				}
				ifile.close();
				ifile.open("Worker.csv");
//				Worker* worker;
				worker = new Worker[workerRecord];
				ifile.getline(temp,100);
				for(int i=0;i<workerRecord;i++)
				{
					memset(temp,'\0',sizeof(temp));
					ifile.getline(temp,100);
					token=strtok(temp,",");
					worker[i].setID(atoi(token));
					token=strtok(NULL,",");
					worker[i].setName(token);
					token=strtok(NULL,",");
					worker[i].setAge(atoi(token));
					token=strtok(NULL,",");
					worker[i].setGender(token);
					token=strtok(NULL,",");
					worker[i].setSalary(atoi(token));
					token=strtok(NULL,",");
					token=strtok(NULL,",");
					worker[i].setYear(atoi(token));
					token=strtok(NULL,",");
					worker[i].setAddress(token);
					token=strtok(NULL,",");
					worker[i].setContact(token);
					token=strtok(NULL,"\0");
					if(strcmp(token,"Active")==0)
					worker[i].setLeave(false);
					else
					worker[i].setLeave(true);
				}
				ifile.close();
				
				while(1)
				{
					std::ifstream a_in;
					std::ofstream a_out;
					system("cls");
					admin_inv.adminDisplay();
					choice = getche();
					Sleep(500);
					switch(choice)
					{
						case '1':
							while(choice != '6'){
								system("cls");
								admin_inv.customerChart();
								choice = getche();
								Sleep(500);
								switch(choice)
								{
									case '1':
										admin->addCustomer(custom,customerRecord);
										getch();
										break;
									case '2':
										admin->deleteCustomer(custom,customerRecord);
										getch();
										break;
									case '3':
										admin->modifyCustomer(custom,customerRecord);
										getch();
										break;
									case '4':
										admin->searchCustomer(custom,customerRecord);
										getch();
										break;
									case '5':
										admin->sortCustomer(custom,customerRecord);
										getch();
										break;
									case '6':
										break;
								}
							}
							break;
						case '2':
							while(choice != '0'){
								system("cls");
								admin_inv.employeeChart();
								choice = getche();
								Sleep(500);
								switch(choice)
								{
									case '1':
										admin->addEmployee(worker,workerRecord);
										break;
									case '2':
										admin->deleteEmployee(worker,workerRecord);
										break;
									case '3':
										admin->searchEmployee(worker,workerRecord);
										break;
								}
							}
							break;
						case '3':
							system("cls");
							char temp[100], match[100];
							std::cout << "\n\n\t\tEnter new password: ";
							std::cin >> temp;
							a_in.open("Admin.txt");
							a_in >> match;
							admin->setName(match);
							a_in >> match;
							admin->setAge(atoi(match));
							a_in >> match;
							admin->setGender(match);
							a_in >> match;
							admin->setID(atoi(match));
							admin->setPassword(temp);
							a_in.close();
							a_out.open("temp.txt");
							a_out << admin->getName() << std::endl;
							a_out << admin->getAge() << std::endl;
							a_out << admin->getGender() << std::endl;
							a_out << admin->getID() << std::endl;
							a_out << admin->getPassword();
							a_out.close();
							system("cls");
							break;
						case '4':
							std::cout << "\n\n\t\t    Are you sure you want to exit? (Y/N): ";
							std::cin >> choice;
							if( choice == 'y' || choice == 'Y' )
							{
								system( "color 0F" );
								quit();
								delete [] custom;
								delete admin;
								return 0;
							}
							break;
					}
				}
				break;
			case '3':
				std::cout << "\n\n\t\t    Are you sure you want to exit? (Y/N): ";
				std::cin >> choice;
				if( choice == 'y' || choice == 'Y' )
				{
					system( "color 0F" );
					quit();
					return 0;
				}
				else
				break;
		}
	}
	return 0;
}

std::string hidePass()
{
	std::string pass;
	
	DWORD mode, count;
  HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
  HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
   SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );
   
  char c;
  while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
    {
    if (c == '\b')
      {
      if (pass.length())
        {
        WriteConsoleA( oh, "\b \b", 3, &count, NULL );
        pass.erase( pass.end() -1 );
        }
      }
    else
      {
      WriteConsoleA( oh, "*", 1, &count, NULL );
      pass.push_back( c );
      }
    }
  SetConsoleMode( ih, mode );
  return pass;
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GUI()
{
	SetConsoleTitle("SUPER MARKET MANAGEMENT");
	system( "color 0F" );
	for(int i=10;i<71;i++)
	{
		gotoxy(i,5);
		Sleep(30);
		std::cout << "/";
	}
	for(int i=70;i>=10;i--)
	{
		gotoxy(i,15);
		Sleep(30);
		std::cout << "/";
	}
	for(int j=6;j<=15;j++)
	{
		gotoxy(10,j);
		Sleep(100);
		std::cout << "-";
	}
	for(int j=15;j>=6;j--)
	{
		gotoxy(70,j);
		Sleep(100);
		std::cout << "-";
	}
	gotoxy(25,10);
	std::cout << "   WELCOME TO SFT SUPER MARKET";
	gotoxy(5,20);
	std::cout << "System made by: \n\tShehmeer Adil\n\tM.Fahad Khalid\n\tM.Taha Wahab";
	for( int k=0;k<6;k++ )
	{
		SetConsoleTextAttribute( hstdout, 0x07 );
		Sleep(600);
		for(int i=10;i<71;i++)
		{
			gotoxy(i,5);
			std::cout << "/";
		}
		for(int i=70;i>=10;i--)
		{
			gotoxy(i,15);
			std::cout << "/";
		}
		for(int j=6;j<=15;j++)
		{
			gotoxy(10,j);
			std::cout << "-";
		}
		for(int j=15;j>=6;j--)
		{	
			gotoxy(70,j);
			std::cout << "-";
		}
		if(k == 0)
		SetConsoleTextAttribute( hstdout, 0x0C );
		else if(k == 1)
		SetConsoleTextAttribute( hstdout, 0x0B );
		else if(k == 2)
		SetConsoleTextAttribute( hstdout, 0x0A );
		else if(k == 3)
		SetConsoleTextAttribute( hstdout, 0x0D );
		else if(k == 4)
		SetConsoleTextAttribute( hstdout, 0x0E );
		else
		SetConsoleTextAttribute( hstdout, 0x0F );
		gotoxy(25,10);
		std::cout << "   WELCOME TO SFT SUPER MARKET";
	}
	SetConsoleTextAttribute( hstdout, 0x07 );
	system("cls");
}

void loading()
{
	std::cout << std::setw(20) << " " << "\n\n\t\t\t\t LOADING...\n\t\t\t     ";
	SetConsoleTextAttribute( hstdout, 0x0C );
	std::cout << "               \r";
	SetConsoleTextAttribute( hstdout, 0xF0 );
	std::cout << "\t\t\t     ";
	SetConsoleTextAttribute( hstdout, 0xCF );
	for(int i=0; i<15; i++)
	{
		std::cout<<" ";
		Sleep(250);
	}
	SetConsoleTextAttribute( hstdout, 0xF0 );
}

void menuDisplay()
{
	std::cout << "\n\n\t\t\t\tSUPER MARKET MANAGEMENT\n\t\t";
	for(int i=0; i<50; i++)
	std::cout << "=";
	std::cout << std::endl << std::endl << std::setw(20) << " " << "1.\t\tCUSTOMER PANEL\n\n";
	std::cout << std::setw(20) << " " << "2.\t\tADMIN PANEL\n\n";
	std::cout << std::setw(20) << " " << "3.\t\tEXIT FROM PROGRAM\n\n\n";
	std::cout << std::setw(20) << " " << "\t   YOUR CHOICE:      ";
}

int checkAccount(char* acc)
{
	std::ifstream ifile;
	char match[100];
	ifile.open("Customer.csv");
	ifile.getline(match,100);
	while(!ifile.eof())
	{
		char* token;
		ifile.getline(match,100);
		token = strtok(match,",");
		if(token == NULL)
		break;
		if(strcmp(token,acc) == 0)
		{
			std::cout << std::endl << std::setw(20) << " " << "\tEnter password: ";
			std::string pass = hidePass();
			char const * ch = pass.c_str();
			token = strtok(NULL,",");
			ifile.close();
			if(strcmp(token,ch) == 0)
			return 1;	// account matched
			else
			return -1;	// wrong password
		}
	}
	ifile.close();
	return 0;			// no such account
}

int checkAdmin(char* acc)
{
	std::ifstream ifile;
	char match[100];
	ifile.open("Admin.txt");
	for(int i=0;i<3;i++)
	ifile.getline(match,100);
	ifile.getline(match,100);
	if(strcmp(acc,match) == 0)
	{
		std::cout << "\n\t\t\t   Enter password: ";
		std::string pass = hidePass();
		char const * ch = pass.c_str();
		ifile.getline(match,100);
		ifile.close();
		if(strcmp(match,ch) == 0)
		return 1;
		else
		return -1;
	}
	ifile.close();
	return 0;
}

int validCode()
{
	system( "cls" );
	int i=0 , k=0 , credit[12] , sum1=0 , sum2=0 , valid , check_digit;
	char code[50] , ch , test[3];
	printf( "\n\t\t\tEnter 12 digit code: " );
	scanf( "%c" , &ch );
	while( i < 12 )
	{
		code[i] = ch;
		scanf( " %c" , &ch );
		i++;
	}
	code[i] = ch;
	code[i+1] = '\0';
	for( i=1; i<=12; i++ )
	{
		test[0] = code[i];
		strcat( test , "\0" );
		credit[k] = atoi( test );
		k++;
	}
	for( i=0; i<12; i+=2 )
	{
		sum1 += credit[i];
	}
	for( i=1; i<11; i+=2 )
	{
		sum2 += credit[i];
	}
	valid = (sum1 * 3) + sum2;
	check_digit = valid % 10;
	if( check_digit != 0 )
	check_digit = 10 - check_digit;
	if( check_digit == credit[11] )
	return 1;
	else
	return 0;
}

void quit()
{
	system("cls");
	std::cout << "\n\n\t\t\tTHANK YOU FOR VISITING\n\t\t\t\t";
	std::cout << "System made by: \n\t\t\t\tShehmeer Adil\n\t\t\t\tM.Fahad Khalid\n\t\t\t\tM.Taha Wahab";
}

void payInfo()
{
	system( "cls" );
	printf("\n\t\t  You can pay the bill through cash,\n" );
	printf( "\t\tbut an amount of more than 100,000 cannot\n" );
	printf( "\t\t      be paid through cash.\n\n");
	printf( "\t\t    Credit cards are also accepted\n" );
	printf( "\t        The scanner verifies the 12-digit code scanned\n" );
	printf( "\t\tby comparing the code’s last digit to its\n" );
	printf( "\t\town computation of the check digit from\n" );
	printf( "\t\tthe first 11 digits as follows:\n" );
	printf( "\t\t1. Calculate the sum of the digits\n" );
	printf( "\t        in the odd-numbered positions multipled by 3\n" );
	printf( "\t\t2. Calculate the sum of the digits\n" );
	printf( "\t        in the even-numbered positions and add this\n" );
	printf( "\t\t     to the previous result.\n" );
	printf( "\t\tIf the last digit of the result from step 2\n" );
	printf( "\t\tis 0, then 0 is the check digit. Otherwise\n" );
	printf( "\t\t       subtract the last digit from 10\n" );
	printf( "\t\t      to calculate the check digit.\n");
	printf( "\t\tIf the check digit matches the final digit\n" );
	printf( "\t\tof the 12-digit code, the credit card is validated\n\n" );
	printf( "\t\tYou can also pay through your account, which\n" );
	printf( "\t\t  has a discount policy of its own\n\n" );
	system( "pause" );
}
