using System;
using System.Collections.Generic;

namespace ThreeSum {

public class Solution {
	public static void Main(string[] args) {
        	int[] nums = {-1,0,1,2,-1,4};
        	 Console.WriteLine("START");
            Solution.ThreeSum(nums);
            Console.WriteLine("DONE");
        }
        
        public static IList<IList<int>> ThreeSum(int[] nums) {
        IList<IList<int>> res = new List<IList<int>>();
        	Array.Sort(nums);
        	int i = 0;
        	while (i < nums.Length && nums[i] <= 0) {
        		int complement = 0 - nums[i];
        		int begin = i + 1;
        		int end = nums.Length - 1;
				Console.WriteLine(i + " " + complement + " " + begin + " " + end + "\n\n");
        		while (begin < end) {
        			int sum = nums[begin] + nums[end];
					Console.WriteLine(sum + " " + nums[begin] + " " + nums[end]);
        			if (sum < complement) {
        				begin++;
        			}
        			else if (sum > complement) {
        				end--;
        			}
        			else {
        				Console.WriteLine(nums[i] + "\t" + nums[begin] + "\t" + nums[end]);
        				IList<int> sol = new List<int>();
        				sol.Add(nums[i]);
        				sol.Add(nums[begin]);
        				sol.Add(nums[end]);
        				res.Add(sol);
        				begin++;
        				end--;
        			}
        		}
				i++;
        	}
        	return res;
   		}
   	}
}