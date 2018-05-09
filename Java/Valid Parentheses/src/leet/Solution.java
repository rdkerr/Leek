package leet;

import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
    	Stack<String> parentheses = new Stack<>();
    	for(int i = 0 ; i < s.length() ; i ++) {
    		String current = s.substring(i,i+1);
    		if(current.equals("{")) {
    			parentheses.push("}");
    		}
    		else if(current.equals("[")) {
    			parentheses.push("]");
    		}
    		else if(current.equals("(")) {
    			parentheses.push(")");
    		}
    		else {
    			if(current.equals(parentheses.peek())) {
    				parentheses.pop();
    			}
    			else {
    				return false;
    			}
    		}
    	}
        return parentheses.isEmpty();
    }
    
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.println(sol.isValid("()"));
		System.out.println(sol.isValid("()[]{}"));
		System.out.println(sol.isValid("(]"));
		System.out.println(sol.isValid("([)]"));
		System.out.println(sol.isValid("{[]}"));

	}

}
