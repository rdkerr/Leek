package leet;

public class AddTwoNumbers {

	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);
		ListNode temp1 = new ListNode(8);
		ListNode temp2 = new ListNode(3);
		l1.next = temp1;
		temp1.next = temp2;
		ListNode l2 = new ListNode(5);
		ListNode temp3 = new ListNode(6);
		ListNode temp4 = new ListNode(4);
		l2.next = temp3;
		temp3.next = temp4;
		addTwoNumbers(l1,l2);
	}
	
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode itr1 = l1, itr2 = l2, l3, temp;
		boolean carryBit = false;
		String solution = "";
		while(itr1 != null || itr2 != null) {
			int val1, val2;
			if(itr1 == null) {
				val1 = 0;
			}
			else {
				val1 = itr1.val;
			}
			if(itr2 == null) {
				val2 = 0;
			}
			else {
				val2 = itr2.val;
			}
			int total = val1 + val2;
			if(carryBit) {
				total++;
				}
			if(total > 9 ) {
				carryBit = true;
				total = total % 10;
			}
			else {
				carryBit = false;
			}
			solution = Integer.toString(total) + solution;
			itr1 = itr1.next;
			itr2 = itr2.next;
		}
		if(carryBit) {
			solution = "1" + solution;
		}
		System.out.println(solution);
		l3 = new ListNode(Integer.parseInt(solution.substring(0,1)));
		for (int i = 1 ; i < solution.length() ; i ++) {
			temp = new ListNode(Integer.parseInt(solution.substring(i,i+1)));
			temp.next = l3;
			l3 = temp;
		}
		return l3;
	}

}
