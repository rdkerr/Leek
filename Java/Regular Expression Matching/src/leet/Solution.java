package leet;

/**
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character. '*' Matches zero or more of the preceding
 * element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be: bool isMatch(const char *s, const char *p)
 * 
 * Some examples: isMatch("aa","a") - false isMatch("aa","aa") - true
 * isMatch("aaa","aa") - false isMatch("aa", "a*") - true isMatch("aa", ".*") -
 * true isMatch("ab", ".*") - true isMatch("aab", "c*a*b") true
 */
public class Solution {
	
	public static void main(String[] args) {
		System.out.println(isMatch("aa", "a*"));
	}

	public static boolean isMatch(String s, String p) {
		if(s == null || p == null) {
            return false;
        }
		boolean [][]T = new boolean[s.length()+1][p.length()+1];
		T[0][0] = true;
		for(int j = 1 ; j < p.length() ; j++) {
			System.out.println("p: " + p.charAt(j));
			if(p.charAt(j)=='*' && T[0][(j+1)-2]) {
				T[0][j+1] = true;
			}
		}
		for(int i = 1 ; i <= s.length() ; i ++) {
			for(int j = 1 ; j <= p.length() ; j++) {
			
				System.out.println("i: " + i +"\ts[i-1]: "+s.charAt(i-1) + "\tj: "+j+ "\tp[j-1]: "+p.charAt(j-1));
				if ((s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='.') && T[i-1][j-1]) {
					T[i][j] = true;
				}
				else if ((p.charAt(j-1)=='*')) {
					if ((s.charAt(i-1)==p.charAt(j-2) || p.charAt(j-2)=='.') && (T[i][j-2] || T[i-1][j])) {
						T[i][j] = true;
					}
					else {
						T[i][j] = T[i][j-2];
					}
				}
			}
			print(T);
		}
		return T[s.length()][p.length()];
	}
	
	public static void print(boolean x[][]) {
		for (boolean[] row : x) {
			for (boolean elem : row) {
				System.out.print(elem + "\t");
			}
			System.out.println();
			System.out.println();
		}
	}

}
