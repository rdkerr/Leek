package leet;

import java.util.ArrayList;
import java.util.List;

public class Solution {
	public List<String> fullJustify(String[] words, int maxWidth) {
		List<String> result = new ArrayList<String>();
		int start = 0;
		while (start < words.length) {
			int end = fitWords(start,words,maxWidth);
			String str = generate(start,end,words,maxWidth);
			result.add(str);
			start = end + 1;
		}
        return result;
    }

	private String generate(int start, int end, String[] words, int maxWidth) {
		int sum = 0;
		for (int i = start ; i <= end ; i ++) {
			sum += words[i].length();
		}
		sum += end - start;
		boolean lastLine = end == words.length-1;
		StringBuilder str = new StringBuilder(maxWidth);
		if (lastLine) {
			for(int i = 0 ; i < (end - start) ; i ++) {
				str.append(words[start+i]);
				str.append(" ");
			}
			str.append(words[end]);
			int remaining = maxWidth - str.length();
			for (int i = 0 ; i < remaining ; i ++) {
				str.append(" ");
			}
		}
		else if(end - start == 0) {
			str.append(words[start]);
			int remaining = maxWidth - str.length();
			for (int i = 0 ; i < remaining ; i ++) {
				str.append(" ");
			}
		}
		else {
			int spaces = end - start;
			int spaceRemaining = (maxWidth - sum) / spaces;
			int extraSpace = (maxWidth - sum) % spaces;
			for(int i = 0 ; i < (end - start) ; i ++) {
				str.append(words[start+i]);
				str.append(" ");
				for(int j = 0 ; j < spaceRemaining; j ++) {
					str.append(" ");
				}
				if (extraSpace > 0) {
					str.append(" ");
					extraSpace--;
				}
			}
			str.append(words[end]);
		}
		return str.toString();
	}


	public int fitWords(int start, String[] words, int maxWidth) {
		int total = words[start].length();
		int end = start + 1;
		while (end < words.length && total + 1 + words[end].length() <= maxWidth) {
			total += 1 + words[end++].length();
		}
		return end - 1;
	}
	
	public static void main(String [] args) {
		Solution sol = new Solution();
		String[] list = {"What","must","be","acknowledgment","shall","be"};
		int maxW = 16;
		List<String> res = sol.fullJustify(list, maxW);
		res.forEach(System.out::println);
	}
}
