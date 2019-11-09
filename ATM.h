#ifndef ATM_H
#define ATM_H

class ATM
{
	private:
		int account_num;
		int PIN;
		double balance;
	public:
//			Setter Functions
		void setNum( int );
		void setPIN( int );
		void setBalance( double );
//			Getter Functions
		int getNum() const;
		int getPIN() const;
		double getBalance() const;
//			Other Functions
		void withDraw();
		void withDraw(double);
		void deposit();
		void details() const;
};

#endif
