package leet;

public class Solution {
	public String addBinary(String a, String b) {
		if (a == null || a.length() == 0) {
			return b;
		}
		if (b == null || b.length() == 0) {
			return a;
		}
		
		int i = a.length() - 1;
		int j = b.length() - 1;
		int carry = 0;
		StringBuilder str = new StringBuilder();
		while (i >= 0 || j >= 0 || carry == 1) {
			int fromA = (i >= 0) ? a.charAt(i--) - '0' : 0;
			int fromB = (j >= 0) ? b.charAt(j--) - '0' : 0;
			str.append((fromA + fromB + carry) % 2);
			carry = (fromA + fromB + carry) / 2; 
		}
		return str.reverse().toString();
    }
	
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.println(sol.addBinary("1", "11"));
	}
}
