package leet;

public class Solution {
	
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		if(l1 == null) {
			return l2;
		}
		if(l2 == null) {
			return l1;
		}
		ListNode listOneIterator = l1;
		ListNode listTwoIterator = l2;
		ListNode newHead;
		if(listOneIterator.val <= listTwoIterator.val) {
			newHead = listOneIterator;
			listOneIterator = listOneIterator.next;
		}
		else {
			newHead  = listTwoIterator;
			listTwoIterator = listTwoIterator.next;
		}
		ListNode newListIterator = newHead;
		while(listOneIterator != null) {
			if(listTwoIterator == null || listOneIterator.val <= listTwoIterator.val) {
				newListIterator.next = listOneIterator;
				listOneIterator = listOneIterator.next;
				
			}
			else {
				newListIterator.next  = listTwoIterator;
				listTwoIterator = listTwoIterator.next;
			}
			newListIterator = newListIterator.next;
		}
		newListIterator.next = listTwoIterator;
        return newHead;
    }

	public static void main(String[] args) {
		ListNode a1 = new ListNode(-9);
    	ListNode a2 = new ListNode(3);
    	//ListNode a3 = new ListNode(4);
    	ListNode b1 = new ListNode(5);
    	ListNode b2 = new ListNode(7);
    	//ListNode b3 = new ListNode(4);
    	a1.next = a2;
    	//a2.next = a3;
    	b1.next = b2;
    	//b2.next = b3;
    	Solution sol = new Solution();
    	ListNode result = sol.mergeTwoLists(a1, b1);
    	while(result != null) {
    		System.out.println(result.val);
    		result = result.next;
    	}

	}

}
