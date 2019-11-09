#include "AdminInventory.h"
#include "libraries.h"

void AdminInventory::adminDisplay()
{
	std::cout << "\n\n\t\t\t     WELCOME TO SFT SUPER MARKET\n\t\t";
	for(int i=0; i<50; i++)
	std::cout << "=";
	std::cout << std::endl << std::endl << std::setw(20) << " " << "1.\t\tCUSTOMER MANAGEMENT\n\n";
	std::cout << std::setw(20) << " " << "2.\t\tEMPLOYEE MANAGEMENT\n\n";
	std::cout << std::setw(20) << " " << "3.\t\tCHANGE PASSWORD\n\n";
	std::cout << std::setw(20) << " " << "4.\t\tEXIT FROM PROGRAM\n\n\n";
	std::cout << std::setw(20) << " " << "\t   YOUR CHOICE:      ";
}

void AdminInventory::employeeChart()
{
//	std::cout << "\n\t\t\t     WELCOME TO SFT SUPER MARKET\n\t\t";
//	for(int i=0; i<50; i++)
//	std::cout << "=";
//	std::cout << std::endl << std::endl << std::setw(20) << " " << "1.\t\tADD EMPLOYEE\n\n";
//	std::cout << std::setw(20) << " " << "2.\t\tDELETE EMPLOYEE\n\n";
//	std::cout << std::setw(20) << " " << "3.\t\tMODIFY EMPLOYEE\n\n";
//	std::cout << std::setw(20) << " " << "4.\t\tSEARCH EMPLOYEE\n\n";
//	std::cout << std::setw(20) << " " << "5.\t\tSORT EMPLOYEE\n\n";
//	std::cout << std::setw(20) << " " << "6.\t\tINCREASE SALARY\n\n";
//	std::cout << std::setw(20) << " " << "7.\t\tDECREASE SALARY\n\n";
//	std::cout << std::setw(20) << " " << "8.\t\tGIVE LEAVE\n\n";
//	std::cout << std::setw(20) << " " << "9.\t\tTAKE LEAVE\n\n";
//	std::cout << std::setw(20) << " " << "0.\t\tBACK\n\n";
//	std::cout << std::setw(20) << " " << "\t   YOUR CHOICE:      ";
	std::cout << "\n\tENTER:\n\t\t1 to add employee";
	std::cout << "\n\t\t2 to delete employee";
	std::cout << "\n\t\t3 to search employee";
	std::cout << "\n\t\t0 to go back";
	std::cout << "\n\n\tYour Choice: ";
}

void AdminInventory::customerChart()
{
//	std::cout << "\n\n\t\t\t     WELCOME TO SFT SUPER MARKET\n\t\t";
//	for(int i=0; i<50; i++)
//	std::cout << "=";
//	std::cout << std::endl << std::endl << std::setw(20) << " " << "1.\t\tADD CUSTOMER\n\n";
//	std::cout << std::setw(20) << " " << "2.\t\tDELETE CUSTOMER\n\n";
//	std::cout << std::setw(20) << " " << "3.\t\tMODIFY CUSTOMER\n\n";
//	std::cout << std::setw(20) << " " << "4.\t\tSEARCH CUSTOMER\n\n";
//	std::cout << std::setw(20) << " " << "5.\t\tSORT CUSTOMER\n\n";
//	std::cout << std::setw(20) << " " << "6.\t\tBACK\n\n\n";
//	std::cout << std::setw(20) << " " << "\t   YOUR CHOICE:      ";
	std::cout << "\n\tENTER:\n\t\t1 to add customer";
	std::cout << "\n\t\t2 to delete customer";
	std::cout << "\n\t\t3 to modify customer";
	std::cout << "\n\t\t4 to search customer";
	std::cout << "\n\t\t5 to sort customer";
	std::cout << "\n\t\t6 to go back";
	std::cout << "\n\n\tYour Choice: ";
}
