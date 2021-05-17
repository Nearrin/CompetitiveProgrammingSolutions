# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import copy

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val!=q.val:
            return False
        return self.isSameTree(p.left,q.left)and self.isSameTree(p.right,q.right)
    def flip(self,p):
        if not p:
            return None
        nl=self.flip(p.left)
        nr=self.flip(p.right)
        np=copy.copy(p)
        np.left=nr
        np.right=nl
        np.val=p.val
        return np
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.isSameTree(root,self.flip(root))
        
