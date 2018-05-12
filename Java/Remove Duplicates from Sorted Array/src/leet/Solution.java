package leet;

public class Solution {
	
	public int removeDuplicates(int[] nums) {
		if (nums == null) {
			return 0;
		}
		int j = 1;
	    for (int i = 1 ; i < nums.length ; i ++) {
	    	if (nums[j-1] != nums[i]) {
	    		nums[j] = nums[i];
	    		j++;
	    	}
	    }
	    return j;
    }

	public static void main(String[] args) {
		Solution sol = new Solution();
		int[] nums = {1,2,3,4,5,6};
		System.out.println(sol.removeDuplicates(nums));
	}

}
