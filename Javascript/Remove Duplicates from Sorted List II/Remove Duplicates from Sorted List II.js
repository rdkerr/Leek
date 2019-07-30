/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

function ListNode(val) {
  this.val = val;
  this.next = null;
}

var deleteDuplicates = function(head) {
  if (!head || !head.next) return head;
  let newHead = new ListNode('head');
  let pointer = newHead;
  let node = head;
  while (node) {
    console.log(node);
    if (node.next && node.val === node.next.val) {
      let temp = node.val;
      while (node && node.val === temp) node = node.next;
    } else {
      pointer.next = node;
      pointer = pointer.next;
      node = node.next;
    }
  }
  pointer.next = null;
  return newHead.next;
};
// 1->2->3->3->4->4->5
let root = new ListNode(1);
root.next = new ListNode(2);
let temp = root.next;
temp.next = new ListNode(3);
temp = temp.next;
temp.next = new ListNode(3);
temp = temp.next;
temp.next = new ListNode(4);
temp = temp.next;
temp.next = new ListNode(4);
temp = temp.next;
temp.next = new ListNode(5);

deleteDuplicates(root)
let t = root;
while (t!== null) {
  console.log('t',t.val);
  t = t.next;
}
