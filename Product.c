#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Product.h"

const char* typeStrings[numOfTypes] = { "Shelf","Frozen","Fridge","FruitVegtable" };

int initProduct(Product* pProduct) {
	if (!pProduct) return 0; //check if pProduct is NULL

	scanProductName(pProduct);
	scanProductType(pProduct);
	scanProductPrice(pProduct);
	scanProductStock(pProduct,0);
	return 1;
}

void freeProduct(Product* pProduct) {
	free(pProduct);
}

//print product
void printProduct(const Product* pProduct) {
	printf("%-25s%-15s%-20s%-10.2f%-4d\n", pProduct->name, pProduct->barcode, typeStrings[pProduct->type], pProduct->price, pProduct->stock);
}

//scans valid barcode for product
void scanBarcode(Product* pProduct) {
	char temp[TEMP_BARCODE_LEN];
	getValidBarcode(temp);
	strcpy(pProduct->barcode, temp);
	pProduct->barcode[BARCODE_LEN] = '\0';
}

void getValidBarcode(char* temp) {
	int numOfDigits;
	do {
		printf("\nEnter product barcode Code should be of 7 length exactly\nUPPER CASE letter and digits\nMust have 3 to 5 digits\nFirst and last chars must be UPPER CASE letter\nFor example A12B40C\n\n");
		fgets(temp, TEMP_BARCODE_LEN, stdin);

		numOfDigits = countDigits(temp); // count of digits in the barcode

		if (strlen(temp) != BARCODE_LEN + 1) {// barcode is not 7 chars
			printf("Code should be of 7 length exactly");
		}
		else if (countLowerCaseLetters(temp)) { // there are lower case letters in barcode
			printf("Code cannot contain lower case letters!");
		}
		else if (!isupper(temp[0]) || !isupper(temp[BARCODE_LEN - 1])) { //first and last chars are not UPPER CASE
			printf("First and last chars must be UPPER CASE letters!!");
		}
		else if (numOfDigits < 3 || numOfDigits > 5) { //the are not 3-5 digits in barcode
			printf("Must have 3 to 5 digits!");
		}
		else if (!validChars(temp)) {
			printf("Only UPPER CASE letters and digits!");
		}
		else {
			break; //means that the barcode is valid!
		}
		printf("\n"); //cosmetic
	} while (1);
}

int validChars(const char* str){
	int size = strlen(str) - 1;
	for (int i = 0; i < size; i++) {
		if ( ( !(str[i] >= 'A' && str[i] <= 'Z' ) && !(str[i] >= '0' && str[i] <= '9'))) { //check if valid
			return 0;
		}
	}
	return 1;
}

//returns the amout of lower case letters in string
int countLowerCaseLetters(const char* str) {
	int count=0;
	int size = strlen(str);
	for (int i = 0; i < size; i++) {
		if (islower(str[i])){
			count++;
		}
	}
	return count;
}

//returns the amount of digits in a string
int countDigits(const char* str) {
	int count = 0;
	int size = strlen(str);
	for (int i = 0; i < size; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			count++;
		}
	}
	return count;
}

//scans product name
void scanProductName(Product* pProduct) {
	printf("Please enter product's name (up to 20 chars): \n");
	fgets(pProduct->name,PRODUCT_NAME_LEN,stdin);// assuming the products name can contain numbers
	pProduct->name[strlen(pProduct->name)-1] = '\0';
}

//scans the type of the product using enum
void scanProductType(Product* pProduct) {
	int type;
	do {
		printf("\nPlease enter one of the following: ");
		for (int i = 0; i < numOfTypes; i++) {
			printf("\n%d for %s", i, typeStrings[i]);
		}
		printf("\n");
		scanf("%d", &type);
		getchar();//buffer clean
		
		if (type < 0 || type >= numOfTypes) { //check if not valid
			printf("you entered a non valid number!\n");
		}
		else {
			break; //valid type!
		}
	} while (1);
	
	pProduct->type = type;
}

//scans the products price
void scanProductPrice(Product* pProduct) {
	float price;
	do {
		printf("Please enter product price: \n");
		scanf("%f", &price);
		getchar(); //buffer clean!
		if (price < 0) { //check if not valid
			printf("\nprice cannot be negative\n");
		}
		else {
			break; // valid
		}
	} while (1);
	pProduct->price = price;
}

//if flag = 0 init stock, else update stock
void scanProductStock(Product* pProduct,int flag) {
	int stock;
	do {
		if (!flag) {
			printf("Please enter product stock: \n");
		}
		else {
			printf("How many items to add to stock?: \n");
		}
		scanf("%d", &stock);
		getchar(); //buffer clean!
		if (stock < 0) { //check if not valid
			printf("stock cannot be negative\n");
		}
		else {
			break; // valid
		}
	} while (1);

	if (!flag) {
		pProduct->stock = stock;
	}
	else {
		pProduct->stock += stock;
	}
}
