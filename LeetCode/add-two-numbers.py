# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def add(self, l1, l2, c):
        if not l1 and not l2 and not c:
            return None
        if not l1:
            l1=ListNode(0)
        if not l2:
            l2=ListNode(0)
        new_v=l1.val+l2.val+c
        new_c=new_v//10
        new_v%=10
        t=ListNode(new_v)
        t.next=self.add(l1.next,l2.next,new_c)
        return t
        
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.add(l1,l2,0)
        
