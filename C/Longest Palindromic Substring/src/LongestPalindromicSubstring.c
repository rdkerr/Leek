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
	// Manachers Algorithm
	int n = strlen(s);
	int m = 2 * n+1;
		int j = 0;
		char * r = (char *)malloc((m+1) * sizeof(char));
		for (int i = 0 ; i < m ; i++) {
			if(i % 2 != 0) {
				r[i] = s[j];
				j++;
			}
			else {
				r[i] = '$';
			}
		}
		r[m] = '\0';
		int * T = (int *)malloc((m) * sizeof(int));
		int center = 0;
		int right = 0;
		int max = 0 ;
		int maxI = 0;
		for (int i = 1 ; i <= m ; i++) {
			int mirror = 2 * center - i;
			T[i] = 1;
			if (i < right) {
				if (right - i < T[mirror]) {
					T[i] = right - i;
				}
				else {
					T[i] = T[mirror];
				}
			}
			while(r[i + T[i]] == r[i - T[i]] && i + T[i] <= m && i - T[i] >= 0) {
				T[i]++;
			}
			T[i]--;
			if (i + T[i] > right) {
				center = i;
				right = i + T[i];
			}
			if (T[i] > max) {
				max = T[i];
				maxI = i;
			}
			printf("%d : %d : %c\n", i, T[i], r[i]);
			int zz = T[i];
		}
	/** Some errors in test cases
	//Tushar Roy algorithm
	// Pad '$'s to even strings to guarantee all are odd
	int n = strlen(s);
	int m = 2 * n + 1;
	int j = 0;
	char * r = (char *)malloc((m+1) * sizeof(char));
	for (int i = 0 ; i < m ; i++) {
		if(i % 2 != 0) {
			r[i] = s[j];
			j++;
		}
		else {
			r[i] = '$';
		}
		r[m] = '\0';
	}
	printf("%s\n",r);

	int *T = (int *)malloc(n*sizeof(int));
	int start = 0;
	int end = 0;
	 for(int i=0; i < m; ) {
	            //expand around i. See how far we can go.
	            while(start >0 && end < m-1 && r[start-1] == r[end+1]) {
	                start--;
	                end++;
	            }
	            //set the longest value of palindrome around center i at T[i]
	            T[i] = end - start + 1;
                printf("%d %d %d\n", end, start, (end-start +1));
	            //this is case 2. Current palindrome is proper suffix of input. No need to proceed. Just break out of loop.
	            if(end == n -1) {
	                break;
	            }
	            //Mark newCenter to be either end or end + 1 depending on if we dealing with even or old number input.
	            int newCenter = end + (i%2 ==0 ? 1 : 0);

	            for(int j = i + 1; j <= end; j++) {

	                //i - (j - i) is left mirror. Its possible left mirror might go beyond current center palindrome. So take minimum
	                //of either left side palindrome or distance of j to end.
	            	if (T[i - (j - i)] < 2 * (end - j) + 1) {
	            		T[j] =T[i - (j - i)];
	            	}
	            	else {
	            		T[j] = 2 * (end - j) + 1;
	            	}
	                //Only proceed if we get case 3. This check is to make sure we do not pick j as new center for case 1 or case 4
	                //As soon as we find a center lets break out of this inner while loop.
	                if(j + T[i - (j - i)]/2 == end) {
	                    newCenter = j;
	                    break;
	                }
	            }
	            //make i as newCenter. Set right and left to atleast the value we already know should be matching based of left side palindrome.
	            i = newCenter;
	            end = i + T[i]/2;
	            start = i - T[i]/2;
	        }

	        //find the max palindrome in T and return it.
	        int max = -1, maxI = -1;
	        for(int i = 0; i < n; i++) {
	            int val;
	            if(i%2 == 0) {
	                val = (T[i] -1)/2;
	            } else {
	                val = T[i]/2;
	            }
	            val = T[i]/2;
	            if(max < val) {
	                maxI = val;
	                max = T[i];
	            }
	        }
    printf("%d %d", max, maxI);
    */
	/**
	 *
	 *int max = 0, maxI = 0, maxJ = 0;
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
	}*/

	/**O(n3)
	 * for (int w = 2 ; w < n ; w ++ ) {
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
	}**/

	/** O(n2)
	 * for (int w = 2 ; w <= n - 1 ; w ++) {
		for (int i = 0 ; i < n - w ; i ++) {
			int j = i + w;
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
	}**/
	        /**
	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < n ; j ++) {
			printf("%d", T[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d : %d", max, maxI);
	char *res = (char*)malloc((max+1)*sizeof(char));
	for (int i = (maxI/2) - (max/2),index = 0 ; index < max; i++, index++) {
			res[index] = s[i];
		}
		res[max] = '\0';
		return res;

}

int main(void) {
	char s[] = "eabcb";
	printf("%s",longestPalindrome(s));
	return EXIT_SUCCESS;
}
