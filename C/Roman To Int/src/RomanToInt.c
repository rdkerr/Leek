/*
 ============================================================================
 Name        : RomanToInt.c
 Author      : Roger Kerr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s) {
	int res = 0;
	int len = strlen(s);
	char roman[] = {'I','V','X','L','C','D','M'};
	int values[] = {1,5,10,50,100,500,1000};
	int cCounter = 6;
	int nCounter = 6;
	int i;
	for(i = 0 ; i < len  ; i ++) {
		char current = s[i];
		char next = s[i+1];
		nCounter = cCounter;
		while(current != roman[cCounter]) {
			cCounter--;
		}
		while(next != roman[nCounter]) {
			nCounter--;
		}
		if (nCounter > cCounter) {
			res += values[nCounter];
			res -= values[cCounter];
			i++;
		}
		else {
			res += values[cCounter];
		}
		//printf("%d\t%c\t%c\t%d\n",i,current,next,res);
	}
	return res;
}

int main(void) {
	printf("%d\n", romanToInt("XI"));
	printf("%d\n", romanToInt("IX"));
	printf("%d\n", romanToInt("I"));
	printf("%d\n", romanToInt("MMMCMXCIX"));
	return EXIT_SUCCESS;
}
