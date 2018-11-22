#include <stdio.h>
#include "numconversion.h"
#include <math.h>


// this file holds all the files

// this function will convert binary number to decimal number
long convertToDecimal(char numToConvert[], int index)
{
	int i;
	int lastItemUsed;	// used to hold the index of the last array element
	int power = 0;	
	const int binBase = 2;	// binary base
	long result = 0;

	// find the last index of the array
	for (i = 0; i < index; i++) {
		if (numToConvert[i] == '\0') {
			lastItemUsed = i-1;
			break;
		}
	}

	// starting from the last array index
	// multiply the array element by the binary positional value
	for (i = lastItemUsed; i>=0; i--) {
		if (numToConvert[i] == '1') 
			result += (long)(pow(binBase, power));
		power++;
	}
	return result;
}



// this function converts decimal number into binary number
void convertToBinary(int decimalNumber, char binaryNumber[], int index)
{
	int i = 0;
	int k = 0;	// for tracking result array
	int tempResultArr[34] = { 0 };	
	
	// clearing the existing value of the array
	// replace with the null byte

	for (i = 0; i < index; i++)
		binaryNumber[i] = '\0';

	// divide the decimal number by 2
	// save the remainder
	do {
		tempResultArr[k] = decimalNumber % 2;
		decimalNumber /= 2;
		k++;
	} while (decimalNumber != 0);

	// reverse the tempResultArr element and put into resultArray
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	for (i = 1; i <= k; i++) {
		if (tempResultArr[k - i] == 1)
			binaryNumber[i - 1] = '1';
		else
			binaryNumber[i - 1] = '0';
	}
	
}


// This function will print the result to screen
void printResult(long decimalNumber, char binaryNumber[])
{
	int i=0;
	printf("Converted numbers: \n");
	printf("Binary\t");
	// print the binary digits until the null byte is found
	while (binaryNumber[i] != '\0') {
		printf("%-c", binaryNumber[i]);
		i++;
	}
	printf("\n");
	printf("Decimal\t%-d\n", decimalNumber);
	printf("Octal\t%-o\n", decimalNumber);
	printf("Hex\t%-x\n", decimalNumber);
}



// this function print the welcome message
void printWelcome()
{
	printf("Welcome to the number conversion system\n");
	printf("Using this system you can covert number from one system into another system (e.g. binary -> decimal).\n");
	printf("NOTE: The maximum value allowed to convert is deciman-2147483647\n\n");
}


// this function clears the input buffer
void clearKeyboard()
{
	while (getchar() != '\n')
		;
}
