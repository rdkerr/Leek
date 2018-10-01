class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	def circle(self,head):
		tail = head
		length = 1
		while tail.next != None:
			tail = tail.next
			length += 1
		tail.next = head
		return length

	def rotateRight(self, head, k):
		"""
		:type head: ListNode
		:type k: int
		:rtype: ListNode
		"""
		if not head or head.next == None or k == 0:
			return head
		length = self.circle(head)
		shift = length - (k % length) - 1
		print(shift)
		for i in range(shift):
			head = head.next
		temp = head
		head = head.next
		temp.next = None
		return head

	def printList(self,head):
		temp = ''
		while head != None:
			temp += str(head.val) + ' '
			head = head.next
		print(temp)
		
def main():
	sol = Solution()
	node1 = ListNode(1)
	node2 = ListNode(2)
	node3 = ListNode(3)
	node4 = ListNode(4)
	node5 = ListNode(5)
	node1.next = node2
	node2.next = node3
	node3.next = node4
	node4.next = node5
	head = sol.rotateRight(node1,6)
	sol.printList(head)


if __name__ == "__main__":
	main()
