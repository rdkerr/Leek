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
		// TODO Auto-generated method stub
		System.out.println(isMatch("aa", "a"));			//false
		System.out.println(isMatch("aaa", "aa"));		//false
		System.out.println(isMatch("aa", "a*"));		//true
		System.out.println(isMatch("aa", ".*"));		//true
		System.out.println(isMatch("ab", "."));			//false
		System.out.println(isMatch("aab", "c*a*b"));	//true

	}

	public static boolean isMatch(String s, String p) {
		return true;
	}

}
