#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Item.h"
#include "libraries.h"

class ShoppingCart
{
		std::vector<Item>item_vec;
	public:
		void addItem(Item&);
		double removeItem();
};

#endif
