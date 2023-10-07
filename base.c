#include "project04.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

//returns int representation of string
int string_to_int(char *string, int base) {
	int number;
	int n;
	
    for (int i = strlen(string) - 1; i > -1; i--) {
    	if (string[i] >= '0' && string[i] <= '9') {
   			n = string[i] - '0';	
   		} else if ((string[i] >= 'a' && string[i] <= 'f') || (string[i] >= 'A' && string[i] <= 'F')) {
			if (string[i] == 'a' || string[i] == 'A'){
   				n = 10;
   			} else if (string[i] == 'b' || string[i] == 'B') {
   				n = 11;
   			} else if (string[i] == 'c' || string[i] == 'C') {
   				n = 12;
   			} else if (string[i] == 'd' || string[i] == 'D') {
   				n = 13;
   			} else if (string[i] == 'e' || string[i] == 'E') {
   				n = 14;
   			} else if (string[i] == 'f' || string[i] == 'F') {
   				n = 15;
   			}
   		}
		number = number + n * pow(base, strlen(string) - i - 1);
   	}
   	
    return number;
}

//reverses string for int_to_string function
char *reverse_string(char *string) {
	char *reversed_string = malloc(sizeof(char));
	int j = 0;

	for (int i = strlen(string) - 1; i > -1; i--) {
		reversed_string[j] = string[i];
		j++;
	}
	
	return reversed_string;
	
}

//returns int representation of string in specified format
char *int_to_string(int value, int base) {
	unsigned int val = value;
	char *string = malloc(sizeof(char));
	char int_in_string;
	int count = 0;

	while (val != 0) {
		int integer = val % base;
		if (integer < 10) {
			int_in_string = integer + '0';
		} else if (integer == 10) {
			int_in_string = 'A';
		} else if (integer == 11) {
			int_in_string = 'B';
		} else if (integer == 12) {
			int_in_string = 'C';
		} else if (integer == 13) {
			int_in_string = 'D';
		} else if (integer == 14) {
			int_in_string = 'E';
		} else if (integer == 15) {
			int_in_string = 'F';
		}
		
		string[count] = int_in_string;
		val = val/base;
		count++;
	}	
	return reverse_string(string);
}

//prints leading zeros depending on the base
void print_leading_zeros(char *value, int base) {
	int length = strlen(value);
	int zero_number;

	if (base == 16){
		zero_number = 8 - length;
	} else if (base == 2){
		zero_number = 32 - length;
	}

	for(int i = 0; i < zero_number; i++) {
		printf("0");
	}
}

//outputs integer
void print_value(char *value, int base) {
	if (base == 10)
		printf("%s\n", value);

	else if (base == 16 || base == 2) {
		if(base == 16)
			printf("0x");
		else
			printf("0b");

		print_leading_zeros(value, base);
		printf("%s\n", value);
		
	}
	
}

