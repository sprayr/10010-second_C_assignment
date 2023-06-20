#pragma once

#define BARCODE_LEN 7

typedef  struct {
	char  barcode[BARCODE_LEN + 1];
	float price;
	int count;
}ShoppingItem;


int initShoppingItem(ShoppingItem* pShoppingItem, const char* barcode, const float price, int count);
void printShoppingItem(const ShoppingItem* pShoppingItem);
void freeShoppingItem(ShoppingItem* pShoppingItem);
void updateShoppingItem(ShoppingItem* pShoppingItem, int count);