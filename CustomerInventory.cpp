#include "CustomerInventory.h"
#include "libraries.h"

void CustomerInventory::customerDisplay()
{
	std::cout << "\n\n\t\t\t     WELCOME TO SFT SUPER MARKET\n\t\t";
	for(int i=0; i<50; i++)
	std::cout << "=";
	std::cout << std::endl << std::endl << std::setw(20) << " " << "1.\t\tPURCHASE ITEMS\n\n";
	std::cout << std::setw(20) << " " << "2.\t\tSFT ACCOUNT\n\n";
	std::cout << std::setw(20) << " " << "3.\t\tUSE ATM\n\n";
	std::cout << std::setw(20) << " " << "4.\t\tEXIT FROM PROGRAM\n\n\n";
	std::cout << std::setw(20) << " " << "\t   YOUR CHOICE:      ";
}

void CustomerInventory::accountDisplay()
{
	std::cout << "\n\n\t\t\t     WELCOME TO SFT SUPER MARKET\n\t\t";
	for(int i=0; i<50; i++)
	std::cout << "=";
	std::cout << std::endl << std::endl << std::setw(20) << " " << "1.\t\tUSE ACCOUNT\n\n";
	std::cout << std::setw(20) << " " << "2.\t\tREMOVE ACCOUNT\n\n";
	std::cout << std::setw(20) << " " << "3.\t\tMODIFY ACCOUNT\n\n";
	std::cout << std::setw(20) << " " << "4.\t\tVIEW ACCOUNT\n\n";
	std::cout << std::setw(20) << " " << "5.\t\tBACK\n\n\n";
	std::cout << std::setw(20) << " " << "\t   YOUR CHOICE:      ";
}

void CustomerInventory::itemDisplay()
{
	system("cls");
	printf( "\n\t\t\t\t     CATEGORIES" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
	printf( "\n\n\t\t\t\t1.\tCLOTHES" );
	printf( "\n\t\t\t\t2.\tELECTRONICS" );
	printf( "\n\t\t\t\t3.\tFOODS" );
	printf( "\n\t\t\t\t4.\tGROCERY" );
	printf( "\n\t\t\t\t5.\tMEDICINE" );
	printf( "\n\t\t\t\t6.\tFURNITURE" );
	printf( "\n\t\t\t\t7.\tSPORTS" );
	printf( "\n\t\t\t\t8.\tBACK" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
}

void CustomerInventory::clothesDisplay()
{
	system("cls");
	printf( "\n\t\t\t\t     CLOTHES" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
	printf( "\n\n\t\t\t\t1.\tMEN'S WEAR" );
	printf( "\n\t\t\t\t2.\tWOMEN'S WEAR" );
	printf( "\n\t\t\t\t3.\tPERFUMES" );
	printf( "\n\t\t\t\t4.\tSHOES" );
	printf( "\n\t\t\t\t5.\tBACK" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
}

void CustomerInventory::electricDisplay()
{
	system("cls");
	printf( "\n\t\t\t\t    ELECTRONICS" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
	printf( "\n\n\t\t\t\t1.\tREFRIGERATOR" );
	printf( "\n\t\t\t\t2.\tAIR CONDITIONER" );
	printf( "\n\t\t\t\t3.\tLED TV" );
	printf( "\n\t\t\t\t4.\tMICROWAVE" );
	printf( "\n\t\t\t\t5.\tWASHING MACHINE" );
	printf( "\n\t\t\t\t6.\tBACK" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
}

void CustomerInventory::foodDisplay()
{
	system("cls");
	printf( "\n\t\t\t\t    FOODS" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
	printf( "\n\n\t\t\t\t1.\tCHIPS" );
	printf( "\n\t\t\t\t2.\tCHOCOLATES" );
	printf( "\n\t\t\t\t3.\tBISCUITS" );
	printf( "\n\t\t\t\t4.\tDRINKS" );
	printf( "\n\t\t\t\t5.\tBACK" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
}

void CustomerInventory::groceryDisplay()
{
	system("cls");
	printf( "\n\t\t\t\t    GROCERY" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
	printf( "\n\n\t\t\t\t1.\tFRUITS" );
	printf( "\n\t\t\t\t2.\tVEGETABLES" );
	printf( "\n\t\t\t\t3.\tDAIRY" );
	printf( "\n\t\t\t\t4.\tBAKERY" );
	printf( "\n\t\t\t\t5.\tCEREALS" );
	printf( "\n\t\t\t\t6.\tFROZEN ITEMS");
	printf( "\n\t\t\t\t6.\tBACK" );
	printf( "\n\n\t\t" );
	for(int a=0;a<50;a++)
	printf( "=" );
}
