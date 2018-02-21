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

int getValue(char c) {
	switch(c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int romanToInt(char *s) {
	int res = 0;
	while(*s) {
		int current = getValue(s[0]);
		int next = getValue(s[1]);
		if (current >= next) {
			res += current;
		}
		else {
			res -= current;
		}
		s++;
	}
	return res;
}

int romanToInt2(char* s) {
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
		while(current != roman[cCounter] && cCounter > 0) {
			cCounter--;
		}
		while(next != roman[nCounter]&& nCounter > 0) {
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
	printf("%d\n", romanToInt("DCXXI"));
	return EXIT_SUCCESS;
}
