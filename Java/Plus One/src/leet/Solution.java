package leet;

import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.ArrayList;

public class Solution {
	    public int[] plusOne(int[] digits) {
	    	/**
	    	String temp = Arrays.stream(digits)
	    		.mapToObj(Integer::toString)
	    		.collect(Collectors.joining(""));
	    	String num = String.valueOf((Integer.parseInt(temp) + 1));
	    	int[] arr = Arrays.stream(num.split(""))
	    			.mapToInt(Integer::valueOf)
	    			.toArray();
	    			*/
	    	int carry = (digits[digits.length-1] == 9) ? 1 : 0;
	    	ArrayList<Integer> list = new ArrayList<Integer>();
	    	if (carry == 1) {
	    		list.add(0);
	    	}
	    	else {
	    		list.add(digits[digits.length-1]+1);
	    	}
	    	for (int i = digits.length - 2 ; i >= 0 ; i --) {
	    		int current = digits[i];
	    		if (carry > 0 && current == 9) {
	    			list.add(0,0);
	    			carry = 1;
	    		}
	    		else if (carry > 0) {
	    			list.add(0,current + 1);
	    			carry = 0;
	    		}
	    		else {
	    			list.add(0,current);
	    			carry = 0;
	    		}
	    	}
	    	if (carry > 0) {
	    		list.add(0,1);
	    	}
	    	int[] arr = new int[list.size()];
	    	int index = 0;
	    	for (Integer num : list) {
	    		arr[index++] = num;
	    	}
	        return arr;
	    }
	
	public static void main(String[] args) {
		Solution sol = new Solution();
		int[] t = sol.plusOne(new int[] {9,8,7,6,5,4,3,2});
		for (int i : t) {System.out.println(i);}
	}
}
