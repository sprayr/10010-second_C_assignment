#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShoppingCart.h"


int initShoppingCart(ShoppingCart* pShoppingCart) {
	pShoppingCart->items = (ShoppingItem**)malloc(sizeof(ShoppingItem*));
	if (!pShoppingCart->items) {
		return 0;
	}
	pShoppingCart->numOfItems = 0;
	return 1;
}

void printShoppingCart(const ShoppingCart* pShoppingCart) {
		float bill = 0;
	if (!pShoppingCart) {
		printf("Shopping cart is empty!");
	}
	else {

		for (int i = 0; i < pShoppingCart->numOfItems; i++) {
			printShoppingItem(pShoppingCart->items[i]);
			bill += (pShoppingCart->items[i]->price) * (pShoppingCart->items[i]->count);
		}
	}
	printf("Total bill:\t%.2f\n", bill);
}

void freeShoppingCart(ShoppingCart* pShoppingCart) {
	for (int i = 0; i < pShoppingCart->numOfItems; i++) {
		freeShoppingItem(pShoppingCart->items[i]);
	}
	free(pShoppingCart);
}

int addShoppingItemToCart(ShoppingCart* pCart, const char* barcode, const float price, int count) {
	if (!pCart->items) {
		pCart->items = (ShoppingItem**)malloc(sizeof(ShoppingItem*));
		if (!pCart->items) {
			return 0;
		}
	}
	int index = isItemInCart(pCart, barcode);
	if ( index == -1) {
		pCart->items = (ShoppingItem**)realloc(pCart->items, sizeof(ShoppingItem*) * (pCart->numOfItems + 1));
		if (!pCart->items) {
			freeShoppingCart(pCart);
			return 0;
		}
		pCart->items[pCart->numOfItems] = (ShoppingItem*)malloc(sizeof(ShoppingItem));
		if (!pCart->items[pCart->numOfItems]) {
			freeShoppingItem(pCart->items[pCart->numOfItems]);	
			return 0;
		}
		return initShoppingItem(pCart->items[pCart->numOfItems++], barcode, price, count);
	}
	updateShoppingItem(pCart->items[index], count);
	return 1;
}

//checks if an item is in the array and returns its index, else returns -1
int isItemInCart(ShoppingCart* pCart, const char* barcode){
	for (int i = 0; i < pCart->numOfItems; i++) {
		if (!strcmp((pCart->items[i])->barcode, barcode)) {
			return i;
		}
	}
	return -1;

}