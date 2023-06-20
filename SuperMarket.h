#pragma once
#include "Customer.h"
#include "Product.h"
#include "Address.h"

typedef struct {
	char* name;
	Address address;
	Customer* customers;
	int numOfCustomers;
	Product* products;
	int numOfProducts;
}SuperMarket;


int initSuperMarket(SuperMarket* pSuperMarket);
void printSuperMarket(const SuperMarket* pSuperMarket);
void printAllProducts(const SuperMarket* pSuperMarket);
void freeSuperMarket(SuperMarket* pSuperMarket);
int addProductToSuperMarket(SuperMarket* pSuperMarket);
int reallocProductsArray(SuperMarket* pSuperMarket);
int addProductToArray(SuperMarket* pSuperMarket, Product* pProduct);
int findBarcode(SuperMarket* pSuperMarket, const char* barcode);
int addCustomer(SuperMarket* pSuperMarket);
void printProdByType(SuperMarket* pSuperMarket);
void printShoppingCartFromSuperMarket(SuperMarket* pSuperMarket);
int getCustomerIndex(SuperMarket* pSuperMarket,const char* name);
void customerShopping(SuperMarket* pSuperMarket);
int areThereCustomersAndProducts(SuperMarket* pSuperMarket);
int doYouWantToShop();
int getHowManyItems(int max);
void superMarketPayment(SuperMarket* pSuperMarket);
void checkOutForExit(SuperMarket* pSuperMarket);