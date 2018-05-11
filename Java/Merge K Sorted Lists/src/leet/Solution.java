package leet;

public class Solution {
	
	 public ListNode mergeKLists(ListNode[] lists) {
		 int length = lists.length;
		 if (length == 0) {
			 return  null;
		 }
		 if (length == 1) {
			 return lists[0];
		 }
		 ListNode newHead = mergeTwoLists(lists[0],lists[1]);
		 for (int i = 2 ; i < length ; i ++) {
			 newHead = mergeTwoLists(newHead,lists[i]);
		 }
		 return newHead;
	 }
	
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
		while(listOneIterator != null && listTwoIterator != null) {
			if(listOneIterator.val <= listTwoIterator.val) {
				newListIterator.next = listOneIterator;
				listOneIterator = listOneIterator.next;
				
			}
			else {
				newListIterator.next  = listTwoIterator;
				listTwoIterator = listTwoIterator.next;
			}
			newListIterator = newListIterator.next;
		}
		if (listOneIterator == null) {
			newListIterator.next = listTwoIterator;
		}
		else {
			newListIterator.next = listOneIterator;
		}
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
    	ListNode c1 = new ListNode(2);
    	ListNode c2 = new ListNode(5);
    	c1.next = c2;
    	ListNode[] lists = new ListNode[3];
    	lists[0] = a1;
    	lists[1] = b1;
    	lists[2] = c1;
    	Solution sol = new Solution();
    	ListNode result = sol.mergeKLists(lists);
    	while(result != null) {
    		System.out.println(result.val);
    		result = result.next;
    	}

	}

}
