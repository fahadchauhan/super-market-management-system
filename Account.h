#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
	private:
		int account_num;
		char* password;
		char* type;
		double balance;
	public:
		Account();
		Account( int, char*, char*, double );
		~Account();
//			Setter Functions
		void setNumber( int );
		void setPassword( char* );
		void setType( char* );
		void setBalance( double );
//			Getter Functions
		int getNumber() const;
		char* getPassword() const;
		char* getType() const;
		double getBalance() const;
//			Other Functions
		void deposit( double );
		void deductBalance( double );
		void display() const;
};

#endif
