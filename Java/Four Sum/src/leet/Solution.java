package leet;

import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class Solution {
	public List<List<Integer>> fourSum(int[] nums, int target) {
		Arrays.sort(nums);
		Set<List<Integer>> results = new HashSet<List<Integer>>();
		int length = nums.length;
		if(length < 4) return new ArrayList<>(results);
		List<Integer> match = new ArrayList<Integer>();
		for(int first = 0 ; first < length - 3 ; first ++) {
			for (int second = first + 1 ; second < length - 2 ; second ++) {
				int third = second + 1;
				int fourth = length - 1;
				int total = target - nums[first] - nums[second];
				while (third < fourth) {
					if(nums[third] + nums[fourth] < total) {
						third++;
					}
					else if (nums[third] + nums[fourth] > total) {
						fourth--;
					}
					else {
						match.add(nums[first]);
						match.add(nums[second]);
						match.add(nums[third]);
						match.add(nums[fourth]);
						results.add(match);
						third++;
						match = new ArrayList<>();
					}
				}
			}
		}
        return new ArrayList<>(results);
    }
	
	public static void main(String[] args) {
		/**Scanner reader = new Scanner(System.in);
		System.out.print("How many numbers will you enter: ");
		int total = reader.nextInt();
		int [] inputArray = new int[total];
		for (int i = 0 ; i < total ; i ++) {
			System.out.print("Enter a number: ");
			inputArray[i] = reader.nextInt();
		}
		System.out.print("What is your target sum: ");
		int targetSum = reader.nextInt();
		**/
		int [] inputArray = {-3,-2,-1,0,0,1,2,3};
		int targetSum = 0;
		Solution sol = new Solution();
		List<List<Integer>> results = sol.fourSum(inputArray,targetSum);
		for(List<Integer> result : results) {
			for (Integer number : result) {
				System.out.print(number + " ");
			}
			System.out.println();
		}
		//reader.close();
	}

}
