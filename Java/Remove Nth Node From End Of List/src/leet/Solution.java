package leet;

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode ret = new ListNode(0);
        ret.next = head;
        ListNode temp = ret;
        ListNode previous = ret;
        int delay = 0 - n - 1;
        while (temp.next != null) {
        	temp = temp.next;
        	delay++;
        	if(delay >= 0) {
        		previous = previous.next;
        	}
        }
        ListNode target = previous.next;
        previous.next = target.next;
        return ret.next;
    }
    
    public static void main(String[] args) {
    	ListNode first = new ListNode(1);
    	/**ListNode second = new ListNode(2);
    	ListNode third = new ListNode(3);
    	ListNode fourth = new ListNode(4);
    	ListNode fifth = new ListNode(5);
    	first.next = second;
    	second.next = third;
    	third.next = fourth;
    	fourth.next = fifth;*/
    	Solution sol = new Solution();
    	ListNode tmp = sol.removeNthFromEnd(first,1);;
    	while(tmp != null) {
    		System.out.print(tmp.val);
    		tmp = tmp.next;
    	}
    }
}