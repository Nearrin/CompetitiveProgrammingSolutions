# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def f(a):
    if not a:
        return (0,0)
    t=f(a.next)
    return (t[0]+1,t[1]+(a.val<<(t[0])))
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        return f(head)[1]
