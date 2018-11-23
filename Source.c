#include <stdio.h>
#include "numconversion.h"

#define INDEX 34	// array index

int main(void)
{
	int choice;
	long decimalNumber, octalNumber, hexNumber;
	char binaryNumber[INDEX], validNumber='n';
	
	// print welcome message to user
	printWelcome();


	do {
		// print option to user
		printf("Please choose one from below- \n\n");
		printf("1. Convert binary number\n");
		printf("2. Convert decimal number\n");
		printf("3. Convert octal number\n");
		printf("4. Convert hexadecimal number\n");
		printf("0. Exit\n");
		printf("Enter your choice nunber: ");
		scanf("%d", &choice);
		// validate the user input
		if (choice < 0 || choice>4)
			printf("Invalid selection. Select a number between 0-4.\n");
		
		// perform action based on user choice
		switch (choice) {
		case 1:
			// Convert the binary number
			do {
				// accept user input
				printf("Enter the binary number: ");
				scanf(" %50[0-1]", binaryNumber);
				// validate if user has input valid binary number
				if (getchar() != '\n') {
					printf("Invalid binary number entered.\n");
					// clear the input buffer
					clearKeyboard();
					validNumber = 'n';
				}
				else {
					validNumber = 'y';
				}
			} while (validNumber == 'n');	// loop until user input valid binary number
			// convert binary to decimal using function
			decimalNumber=convertToDecimal(binaryNumber, INDEX);
			// print the result using function
			printResult(decimalNumber, binaryNumber);
			choice = tryAgain();
			break;
		case 2:
			// convert decimal number
			do {
				// accept user input
				printf("Enter the decimal number: ");
				scanf("%i", &decimalNumber);
				// validate if user has input decimal number
				if (getchar() != '\n') {
					printf("Invalid decimal number entered.\n");
					// clear input buffer
					clearKeyboard();
					validNumber = 'n';
				}
				else {
					validNumber = 'y';
				}
			} while (validNumber == 'n');	// loop until user input valid decimal number
			// convert to binary using function
			convertToBinary(decimalNumber, binaryNumber, INDEX);
			// print result using function
			printResult(decimalNumber, binaryNumber);
			choice = tryAgain();
			break;

		case 3:
			// convert octal number
			do {
				// accept user input of octal number
				printf("Enter the octal number: ");
				scanf("%o", &octalNumber);
				// validate the user input
				if (getchar() != '\n') {
					printf("Invalid octal number entered.\n");
					// clear input buffer
					clearKeyboard();
					validNumber = 'n';
				}
				else {
					validNumber = 'y';
				}
			} while (validNumber == 'n');	// loop until valid number is entered
			// convert to binary using function
			convertToBinary(octalNumber, binaryNumber, INDEX);
			// print result using function
			printResult(octalNumber, binaryNumber);
			choice = tryAgain();
			break;

		case 4:
			// convert hexadecimal number
			do {
				// accept user input
				printf("Enter the hexadecimal number: ");
				scanf("%x", &hexNumber);
				// validate user input
				if (getchar() != '\n') {
					printf("Invalid hexadecimal number entered.\n");
					// clear input buffer
					clearKeyboard();
					validNumber = 'n';
				}
				else {
					validNumber = 'y';
				}
			} while (validNumber == 'n');	// loop until user enter valid number
			// convert to binary using function
			convertToBinary(hexNumber, binaryNumber, INDEX);
			// print result using function
			printResult(hexNumber, binaryNumber);
			choice = tryAgain();
			break;
		case 0:
			// exit program
			printf("Thank you for using number conversion system.Good bye!\n");
		}
		//loop until the option is within this range
	} while (choice != 0);

	return 0;
}