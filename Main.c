#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "SuperMarket.h"

#define SHOW_SUPER "0 - Show SuperMarket\n"
#define ADD_PROD "1 - Add product\n"
#define ADD_CUST "2 - Add customer\n"
#define CUST_SHOP "3 - Customer shopping\n"
#define PRINT_SHOP_CART "4 - Print shopping cart\n"
#define CUST_PAY "5 - Customer pay\n"
#define PRINT_PROD "6 - Print product by type\n"
#define QUIT_MENU "-1 - Quit\n"
#define QUIT -1

void main() {
	int choice = 1;
	SuperMarket super;
	initSuperMarket(&super);
	
	do {
		printf("\nPlease choose one of the following options:\n");
		printf("%s", SHOW_SUPER);
		printf("%s", ADD_PROD);
		printf("%s", ADD_CUST);
		printf("%s", CUST_SHOP);
		printf("%s", PRINT_SHOP_CART);
		printf("%s", CUST_PAY);
		printf("%s", PRINT_PROD);
		printf("%s", QUIT_MENU);
		scanf("%d", &choice);
		getchar(); //buffer clean

		switch(choice){
		//print super market
		case 0: {
			printSuperMarket(&super);
			break;
		}
		//add product to supermarket
		case 1: {
			addProductToSuperMarket(&super);
			break;
		}
		//add customer
		case 2: {
			addCustomer(&super);
			break;
		}
		//customer shopping
		case 3: {
			customerShopping(&super);
			break;
		}
		//print shopping cart
		case 4: {
			printShoppingCartFromSuperMarket(&super);
			break;
		}
		//customer pay
		case 5: {
			superMarketPayment(&super);
			break;
		}
		//print product by type
		case 6: {
			printProdByType(&super);
			break;
		}
		//quit menu
		case -1: {
			printf("Thank you, bye bye!!");
			checkOutForExit(&super);
			freeSuperMarket(&super);
			break;
		}
		default:
		{
			printf("Wrong input!!");
			break; 
		}
		}

	} while (choice != QUIT);
	
	
	
	
	
	
	
}