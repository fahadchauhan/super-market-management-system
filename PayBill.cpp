#include "PayBill.h"
#include "Account.h"
#include "libraries.h"

PayBill::PayBill()
{
	bill = 0;
}

void PayBill::setBill( double bill )
{
	this->bill = bill;
}

double PayBill::getBill() const
{
	return bill;
}

int PayBill::payBill( Account* acc )
{
	
}
