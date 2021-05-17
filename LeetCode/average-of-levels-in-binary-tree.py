# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        cur=[root]
        ans=[]
        def mean(a):
            return sum(a)/len(a)
        while cur:
            ans.append(mean([i.val for i in cur]))
            new_cur=[]
            for i in cur:
                new_cur.append(i.left)
                new_cur.append(i.right)
            cur=[i for i in new_cur if i]
        return ans
        
