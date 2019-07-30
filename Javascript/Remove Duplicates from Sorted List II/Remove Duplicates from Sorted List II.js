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

var deleteDuplicates = function(head, current = undefined) {
  if (!head) return;
  let node = head;
  let prev;
  while (node) {
    if (!prev) {
      prev = node;
      node = node.next;
    } else {
      if (prev.val === node.val) {
        prev.next = node.next;
        node = node.next;
      } else {
        prev = node;
        node = node.next;
      }
    }
  }
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
console.log('a',t);
while (t!== null) {
  console.log('t',t.val);
  t = t.next;
}
