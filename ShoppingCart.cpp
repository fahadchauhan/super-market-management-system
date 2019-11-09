#include "ShoppingCart.h"
#include "libraries.h"

void ShoppingCart::addItem( Item& item )
{
	item_vec.push_back(item);
}

double ShoppingCart::removeItem()
{
	item_vec.pop_back();
}
