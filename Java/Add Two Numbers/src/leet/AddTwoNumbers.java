package leet;

public class AddTwoNumbers {

	public static void main(String[] args) {
		System.out.println("HI");
		ListNode l1 = new ListNode(2);
		ListNode temp1 = new ListNode(4);
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
		// Sample strings are same length
		while(itr1 != null) {
			int total = itr1.val + itr2.val;
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
		l3 = new ListNode(Integer.parseInt(solution.substring(solution.length()-1,solution.length())));
		for (int i = solution.length()-1 ; i > 0 ; i--) {
			
		}
		return null;
	}

}
