package leet;

import java.util.ArrayList;
import java.util.List;

public class Solution {
	public List<String> fullJustify(String[] words, int maxWidth) {
		List<String> result = new ArrayList<String>();
        return null;
    }
	
	public static void main(String [] args) {
		Solution sol = new Solution();
		String[] list = {"This", "is", "an", "example", "of", "text", "justification."};
		int maxW = 16;
		System.out.println(
				sol.fullJustify(list, maxW).stream()
				);
	}
}
