#pragma once
#include "ShoppingCart.h"
#include "Product.h"

typedef struct {
	char* name;
	ShoppingCart* pCart;
} Customer;


int initCustomer(Customer* pCustomer);
void freeCustomer(Customer* pCustomer);
void printCustomer(const Customer* pCustomer);
char* createDynamicStr(const char* msg);
void printCustomerShoppingCart(Customer* pCustomer);
void customerAddShoppingItem(Customer* pCustomer, Product* pProduct, int count);
int customerPayment(Customer* pCustomer);