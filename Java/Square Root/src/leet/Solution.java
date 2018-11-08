package leet;

public class Solution {
	public int mySqrt(int x) {
		int ans = 0;
		if (x <= 1) {
			ans = x;
		}
		else {
			int left = 0;
			int right = x;
			int mid = x;
			while (left < right) {
				mid = left + (right - left) / 2;
				if (mid <= x / mid) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
			ans = right - 1;
		}
        return ans;
    }
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.println(sol.mySqrt(4));
		System.out.println(sol.mySqrt(44));
		System.out.println(sol.mySqrt(455));
		System.out.println(sol.mySqrt(4666));
		
	}

}
