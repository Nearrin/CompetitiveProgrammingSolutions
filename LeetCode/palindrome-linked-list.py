# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# O(n),O(1)reverse
def reverse(head):
    cur=None
    while head:
        nxt=head.next
        head.next=cur
        cur=head
        head=nxt
    return cur

def cut_half(head):
    l=0
    p=head
    while p:
        l+=1
        p=p.next
    t=1
    p=head
    while t!=l//2:
        p=p.next
        t+=1
    if l%2==0:
        head2=p.next
        p.next=None
        return head,head2
    else:
        head2=p.next.next
        p.next=None
        return head,head2
    
    
    

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        if not head.next:
            return True
        h1,h2=cut_half(head)
        h2=reverse(h2)
        while h1 and h2:
            if h1.val!=h2.val:
                return False
            h1=h1.next
            h2=h2.next
        return True
        
        
        
