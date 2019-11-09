#ifndef ITEM_H
#define ITEM_H

class Item
{
	private:
		char* name;
		char* type;
		double price;
		int quantity;
	public:
		Item();
		Item( char*, char*, double, int );
		~Item();
			// Setter Functions
		void setName( char* );
		void setType( char* );
		void setPrice( double );
		void setQuantity( int );
			// Getter Functions
		char* getName();
		char* getType();
		double getPrice();
		int getQuantity();
			// Other Functions
		void display() const;
};

#endif
