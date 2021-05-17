# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dls(self,x):
        if not x.left and not x.right:
            return (x.val,1)
        elif not x.left:
            r=self.dls(x.right)
            return (r[0],r[1]+1)
        elif not x.right:
            r=self.dls(x.left)
            return (r[0],r[1]+1)
        else:
            r1=self.dls(x.left)
            r2=self.dls(x.right)
            if r1[1]>r2[1]:
                return r1[0],r1[1]+1
            elif r1[1]<r2[1]:
                return r2[0],r2[1]+1
            else:
                return (r1[0]+r2[0],r1[1]+1)
    def deepestLeavesSum(self, root: TreeNode) -> int:
        return self.dls(root)[0]
        
