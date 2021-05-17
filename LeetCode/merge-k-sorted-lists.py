# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# the right way to used heapq: if the second value is not comparable
# .add a global unique value= =
# also please see how to use heapq

import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        ans=[]
        hp=[]
        for i,n in enumerate(lists):
            if n:
                heapq.heappush(hp,(n.val,i,n))
                lists[i]=n.next
        while hp:
            mi=heapq.heappop(hp)
            ans.append(mi[2])
            if lists[mi[1]]:
                heapq.heappush(hp,(lists[mi[1]].val,mi[1],lists[mi[1]]))
                lists[mi[1]]=lists[mi[1]].next
        for i in range(1,len(ans)):
            ans[i-1].next=ans[i]
        # fk!!!!!!!!!!!
        #!!!!!!!!
        if not ans:
            return None
        ans[-1].next=None
        return ans[0]
                
        
