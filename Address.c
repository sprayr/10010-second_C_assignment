#include "Address.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>




char* remove_white_spaces(char* str) {
	int i = 0, j = 0;
	while (str[i]) {
		if (str[i] != ' ' || (str[i] == ' ' && str[i + 1] != ' ')) {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
	return str;
}

int ifHouseNumberContainsOnlyNumeric(char* num) {///chack if numeric

	int size = strlen(num);
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(num[i])) return 0;
	}
	return 1;

}

void format_address(Address* address) {


	format_name(address->street);
	format_name(address->city);


}

void printAddress(const Address* address) {
	printf("Address: %s %u,%s\n", address->street, address->houseNumber, address->city);
}

void freeAddress(Address* address) {
	free(address->street);
	free(address->city);
}

int countDelimiters(char* str) {//check the delimiters (if it has only 2)
	int size = strlen(str);
	int count = 0;
	if (size == 0) return 0;
	for (int i = 0; i < size; i++) {
		if (str[i] == '#') count++;

	}
	if (count == MAXDELIMITERS) return 1;
	return 0;

}

char* addSpaces(const char* str) {
	int len = strlen(str);
	int num_spaces = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') num_spaces++;
	}
	int new_len = len + num_spaces;
	char* new_str = malloc((new_len + 1) * sizeof(char));
	if (new_str == NULL) {
		printf("Error: Failed to allocate memory.\n");
		return NULL;
	}
	int j = 0;
	for (int i = 0; i < len; i++) {
		new_str[j++] = str[i];
		if (str[i] == ' ') new_str[j++] = ' ';
	}
	new_str[j] = '\0';
	return new_str;
}

void format_name(char* str) {

	int len = strlen(str);
	int i;

	// Convert first letter of first word to uppercase
	if (len > 0) {
		str[0] = toupper(str[0]);
	}

	// Iterate through the rest of the string
	for (i = 1; i < len; i++) {
		if (str[i] == ' ') {
			// If we encounter a space, convert the next character to uppercase
			// if it is not the last word
			if (i + 1 < len) {
				str[i + 1] = toupper(str[i + 1]);
			}
		}
	}

	// Convert the first letter of the last word to lowercase
	for (i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			// We found the start of the last word
			if (i + 1 < len) {
				str[i + 1] = tolower(str[i + 1]);
			}
			break;
		}
	}

}

int initAddress(Address* address) {
	char input_string[MAXLENGTH];
	int dFlag = 1;
	char* street;
	char* house_number_string;
	char* city;

	while (1) {


		printf("Enter the address in the following format: street#house_number#city\n");
		fgets(input_string, MAXLENGTH, stdin);

		dFlag = countDelimiters(input_string);
		if (!dFlag) {
			printf("WRONG FORMAT!!\n ");
		}

		else {


			// Remove leading spaces from input string
			int i = 0;
			while (input_string[i] == ' ') i++;
			int j = 0;
			while (input_string[i] != '\0') {
				input_string[j++] = input_string[i++];
			}
			input_string[j] = '\0';

			street = strtok(input_string, "#");
			house_number_string = strtok(NULL, "#");
			city = strtok(NULL, "#");

			if (street == NULL || house_number_string == NULL || city == NULL) {
				printf("Error: Invalid address format.\n");
				continue;
			}
			int is_numeric = 1;
			for (unsigned int i = 0; i < strlen(house_number_string); i++) {
				if (!isdigit(house_number_string[i])) {
					is_numeric = 0;
					break;
				}
			}
			if (!is_numeric) {
				printf("Error: Invalid house number.\n");
				continue;
			}

			if (sscanf(house_number_string, "%d", &address->houseNumber) != 1) {
				printf("Error: Invalid house number.\n");
				continue;
			}

			street = remove_white_spaces(street);
			city = remove_white_spaces(city);


			address->street = addSpaces(street);///
			address->city = addSpaces(city);

			if (address->street == NULL || address->city == NULL) {
				printf("Error: Failed to allocate memory.\n");
				continue;
			}

			break;
		}
	}


	format_address(address);

	return 1;
}