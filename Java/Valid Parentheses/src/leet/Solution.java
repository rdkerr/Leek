package leet;

import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
    	Stack<Character> parentheses = new Stack<>();
    	for(int i = 0 ; i < s.length() ; i ++) {
    		char current = s.charAt(i);
    		if(current == '{') {
    			parentheses.push('}');
    		}
    		else if(current == '[') {
    			parentheses.push(']');
    		}
    		else if(current == '(') {
    			parentheses.push(')');
    		}
    		else if(parentheses.isEmpty()) {
    			return false;
    		}
    		else {
    			if(current == parentheses.peek()) {
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
