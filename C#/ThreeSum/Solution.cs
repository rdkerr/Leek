using System;
using System.Collections.Generic;

namespace ThreeSum {

public class Solution {
	public static void Main(string[] args) {
        	int[] nums = {0,0,0};
        	 Console.WriteLine("START");
            IList<IList<int>> res = Solution.ThreeSum(nums);
            foreach(var row in res) {
            	string temp = "";
            	foreach(var elem in row) {
            		temp += elem.ToString();
            	}
            	Console.WriteLine(temp);
			}
            Console.WriteLine("DONE");
        }
        
        public static IList<IList<int>> ThreeSum(int[] nums) {
        IList<IList<int>> res = new List<IList<int>>();
        	Array.Sort(nums);
        	int i = 0;
            if (nums.Length < 3) {
                return res;
            }
        	while (i < nums.Length && nums[i] <= 0) {
        		int complement = 0 - nums[i];
        		int begin = i + 1;
        		int end = nums.Length - 1;
        		while (begin < end) {
        			int sum = nums[begin] + nums[end];
        			if (sum < complement) {
        				begin++;
        			}
        			else if (sum > complement) {
        				end--;
        			}
        			else {
        				IList<int> sol = new List<int>();
        				sol.Add(nums[i]);
        				sol.Add(nums[begin]);
        				sol.Add(nums[end]);
        				res.Add(sol);
        				while (nums[begin]==sol[1] && begin < end) {
        					begin++;
        				}
        				while (nums[begin]==sol[2] && begin < end) {
        					end--;
        				}
        			}
        		}
        		while(i < nums.Length-1 && nums[i] == nums[i+1]) {
					i++;
				}
				i++;
        	}
        	return res;
   		}
   	}
}