#pragma once

#define PRODUCT_NAME_LEN 20
#define BARCODE_LEN 7
#define TEMP_BARCODE_LEN 255

typedef enum {Shelf, Frozen, Fridge,FruitVegtable,numOfTypes} ProductType;


typedef struct {
	char name[PRODUCT_NAME_LEN+1];
	char barcode[BARCODE_LEN + 1]; //CAPS and digits only!!!
	ProductType type;
	float price;
	int stock;
}Product;


int initProduct();
void printProduct(const Product* pProduct);
void freeProduct(Product* pProduct);
void scanBarcode(Product* pProduct);
void getValidBarcode(char* temp);
int countLowerCaseLetters(const char* str);
int countDigits(const char* str);
void scanProductName(Product* pProduct);
void scanProductType(Product* pProduct);
void scanProductPrice(Product* pProduct);
void scanProductStock(Product* pProduct,int flag);
int validChars(const char* str);

