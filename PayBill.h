#ifndef PAYBILL_H
#define PAYBILL_H

#include "Account.h"

class PayBill
{
	private:
		double bill;
	public:
		PayBill();
		void setBill( double );
		double getBill() const;
		int payBill( Account* );
};

#endif
