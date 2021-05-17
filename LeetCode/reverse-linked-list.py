# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def reverse(node):
    if not node.next:
        return (node,node)
    tmp=reverse(node.next)
    tmp[1].next=node
    node.next=None
    return (tmp[0],node)

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        return reverse(head)[0]
        
