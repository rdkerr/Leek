package leet;

public class Solution {
	public ListNode swapPairs(ListNode head) {
		if (head == null) {
			return null;
		}
		if (head.next == null) {
			return head;
		}
		ListNode newHead = new ListNode(0);
		newHead.next = head.next;
		ListNode first = head;
		ListNode second = head.next;
		while(first != null && second != null) {
			int temp = first.val;
			first.val = second.val;
			second.val = temp;
			first = second.next;
			if(first != null) {
				second = first.next;
			}
		}
		return head;
    }
	
	public static void main(String[] args) {
		ListNode a1 = new ListNode(1);
    	ListNode a2 = new ListNode(2);
    	ListNode a3 = new ListNode(3);
    	ListNode a4 = new ListNode(4);
    	a1.next = a2;
    	a2.next = a3;
    	a3.next = a4;
    	Solution sol = new Solution();
    	ListNode result = sol.swapPairs(a1);
    	while(result != null) {
    		System.out.println(result.val);
    		result = result.next;
    	}

	}

}
