package leet;

import java.util.Stack;

public class Solution {
	
	public ListNode reverseKGroup(ListNode head, int k) {
		int length = getLength(head);
		if (length == 0) {
			return null;
		}
		int rounds = length / k;
		if (rounds == 0) {
			return head;
		}
		ListNode newHead = new ListNode(0);
		newHead.next = head;
		ListNode temp = head;
		ListNode beforePair = newHead;
		Stack<ListNode> toReverse = new Stack<>();
		// O( n / k) * O(k +k) => O(2n)
		// O(k) space
		for (int i = 0 ; i < rounds ; i++) {
			for (int j = k ; j > 0 ; j --) {
				toReverse.push(temp);
				temp = temp.next;
			}
			beforePair.next = toReverse.pop();
			ListNode toAdd = beforePair.next;
			while(!toReverse.isEmpty()) {
				toAdd.next = toReverse.pop();
				toAdd = toAdd.next;
			}
			toAdd.next = temp;
			beforePair = toAdd;
		}
		return newHead.next;
    }
	
	public int getLength(ListNode list) {
		if (list == null) {
			return 0;
		}
		ListNode temp = list;
		int size = 0;
		while(temp != null) {
			size++;
			temp = temp.next;
		}
		return size;
	}
	
	public static void main(String[] args) {
		ListNode a1 = new ListNode(1);
    	ListNode a2 = new ListNode(2);
    	ListNode a3 = new ListNode(3);
    	ListNode a4 = new ListNode(4);
    	ListNode a5 = new ListNode(5);
    	a1.next = a2;
    	a2.next = a3;
    	a3.next = a4;
    	a4.next = a5;
    	Solution sol = new Solution();
    	ListNode result = sol.reverseKGroup(a1, 2);
    	while(result != null) {
    		System.out.println(result.val);
    		result = result.next;
    	}

	}

}
