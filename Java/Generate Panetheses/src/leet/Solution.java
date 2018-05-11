package leet;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParentheses(int n) {
        List<String> res = new ArrayList<>();
        if (n == 0) {
            res.add("");
        } else {
            for (int i = 0; i < n; ++i)
                for (String left: generateParentheses(i))
                    for (String right: generateParentheses(n-1-i))
                        res.add("(" + left + ")" + right);
        }
        return res;
    }
    
    public static void main(String []args) {
    	Solution sol = new Solution();
    	for(String str: sol.generateParentheses(3)) {
    		System.out.println(str);
    	}
    	
    }
}
