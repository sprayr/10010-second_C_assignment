#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "Product.h" //here to prevent double headering

#define MAX_STR_LEN 255


int initCustomer(Customer* pCustomer) {

	pCustomer->name = createDynamicStr("Please enter customer's name: ");
	if (!pCustomer->name)
		return 0;
	pCustomer->pCart = NULL; //Empty cart
	
	return 1;
}

void freeCustomer(Customer* pCustomer) {
	free(pCustomer->name);
	if (!pCustomer->pCart) {
		free(pCustomer->pCart);
	}
	free(pCustomer);
}

void printCustomer(const Customer* pCustomer) {
	printf("Customer's name: %s", pCustomer->name);
	printf("\t\t");
	if (!pCustomer->pCart) {
		printf("Shopping cart is empty!\n");
		return;
	}
	printf("Doing shopping now!!!\n");
}

char* createDynamicStr(const char* msg) {
	char* str;
	char temp[MAX_STR_LEN];
	printf(msg);

	fgets(temp, MAX_STR_LEN, stdin);
	int size = strlen(temp);
	str = (char*)malloc((size + 1) * sizeof(char));
	if (!str)
		return NULL;
	strcpy(str, temp);
	str[size - 1] = '\0';
	return str;
}

void printCustomerShoppingCart(Customer* pCustomer) {
	printShoppingCart(pCustomer->pCart);
}

void customerAddShoppingItem(Customer* pCustomer, Product* pProduct, int count) {
	if (!pCustomer->pCart) {
		pCustomer->pCart = (ShoppingCart*)malloc(sizeof(ShoppingCart));
		if (!initShoppingCart(pCustomer->pCart)) {
			return; 
		}
	}
	if (!addShoppingItemToCart(pCustomer->pCart, pProduct->barcode, pProduct->price, count)){
		printf("Error ocoured while adding your product to cart.");
		return;
	}
}

int customerPayment(Customer* pCustomer) {
	if (!pCustomer->pCart) {
		return 0;
	}
	
	printShoppingCart(pCustomer->pCart);
	freeShoppingCart(pCustomer->pCart);
	pCustomer->pCart = NULL;
	printf("\n------------Payment received------------\n");
	return 1;
}