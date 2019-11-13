# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        r = None
        carry = 0
        while l1 or l2 or carry:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            calc = x+y+carry
            carry = 1 if calc >= 10 else 0
            val = calc % 10
            if not r:
                p = ListNode(val)
                r = p
            else:
                p.next = ListNode(val)
                p = p.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return r
