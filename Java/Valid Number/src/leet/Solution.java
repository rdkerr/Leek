package leet;

public class Solution {
	public boolean isNumber(String s) {
        return s.trim().matches("[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?");
    }
	
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.println(sol.isNumber("--6"));
		System.out.println(sol.isNumber("e3"));
		System.out.println(sol.isNumber("+-3"));
		System.out.println(sol.isNumber("1 a"));
		System.out.println(sol.isNumber("6e-1"));

	}

}
