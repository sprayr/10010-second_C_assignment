#pragma once
#include "ShoppingItem.h"

typedef struct {
	ShoppingItem** items;
	int numOfItems;
}ShoppingCart;



int initShoppingCart(ShoppingCart* pShoppingCart);
void printShoppingCart(const ShoppingCart* pShoppingCart);
void freeShoppingCart(ShoppingCart* pShoppingCart);
int addShoppingItemToCart(ShoppingCart* pCart,const char* barcode, const float price,int count);
int isItemInCart(ShoppingCart* pCart,const char* barcode);
