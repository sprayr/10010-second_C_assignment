#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXLENGTH 255
#define MAXDELIMITERS 2

typedef struct {

	unsigned int houseNumber;
	char* street;
	char* city;
}Address;


int initAddress(Address* address);
void format_name(char* name);
void format_address(Address* address);
void printAddress(const Address* address);
void freeAddress(Address* address);
char* remove_white_spaces(char* str);
int countDelimiters(char* str);




