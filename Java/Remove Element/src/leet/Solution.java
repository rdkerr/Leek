package leet;

public class Solution {
	public int removeElement(int[] nums, int val) {
		int current = 0;
		int length = nums.length;
	    for (int i = 0 ; i < length ; i ++) {
	    	if (nums[i] != val) {
	    		nums[current++] = nums[i];
	    	}
	    }
	    return current;
	}
	
	public static void main(String[] args) {
		Solution sol = new Solution();
		int[] nums = {3,2,2,3};
		System.out.println(sol.removeElement(nums,3));
		for (int i : nums) {
			System.out.println(i);
		}
	}



}
