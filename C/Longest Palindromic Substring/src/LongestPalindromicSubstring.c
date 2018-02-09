/*
 ============================================================================
 Name        : LongestPalindromicSubstring.c
 Author      : Roger Kerr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// T(i,i) = 1
// T(i,i+1) = 2 if xi == xi +1
// T(i,j) = 2 + T(i-1,j-1) if xi == xj
// 			0				otherwise


#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
	int n = strlen(s);
	int max = 0, maxI = 0, maxJ = 0;
	int **T = (int **)malloc(n * sizeof(int *));
	for (int i=0; i<n; i ++) {
		T[i] = (int *)malloc(n * sizeof(int));
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			T[i][j]=0;
		}
	}
	for (int i = 0; i < n ; i++) {
		T[i][i] = 1;
		if(s[i] == s[i+1]) {
			T[i][i+1] = 2;
			max = 2;
		}
	}

	for (int w = 2 ; w < n ; w ++ ) {
		for (int i = 0 ; i < n - w; i ++ ) {
			int j = i + w;
			for (int l = i ; l < j - 1; l ++) {
				if (s[i] == s[j] && T[i+1][j-1] > 0) {
					T[i][j] = 2 + T[i+1][j-1];
					if(T[i][j] > max) {
						max = T[i][j];
						maxI = i;
						maxJ = j;
					}
				}
				else {
					T[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < n ; j ++) {
			printf("%d", T[i][j]);
		}
		printf("\n");
	}
	char *res = malloc(maxJ-maxI+1);
	for (int i = 0 ; i < maxJ-maxI+1 ; i++) {
		res[i] = s[maxI +i];
	}
	res[maxJ-maxI+1] = '\0';
	return res;
}

int main(void) {
	char* s = "abcda";
	printf("%s",longestPalindrome(s));
	return EXIT_SUCCESS;
}
