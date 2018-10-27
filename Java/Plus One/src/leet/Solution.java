package leet;

import java.util.Arrays;
import java.util.stream.Collectors;

public class Solution {
	    public int[] plusOne(int[] digits) {
	    	String temp = Arrays.stream(digits)
	    		.mapToObj(Integer::toString)
	    		.collect(Collectors.joining(""));
	    	String num = String.valueOf((Integer.parseInt(temp) + 1));
	    	int[] arr = Arrays.stream(num.split(""))
	    			.mapToInt(Integer::valueOf)
	    			.toArray();
	        return arr;
	    }
	
	public static void main(String[] args) {
		Solution sol = new Solution();
		int[] t = sol.plusOne(new int[] {9,8,7,6,5,4,3,2});
		for (int i : t) {System.out.println(i);}
	}
}
