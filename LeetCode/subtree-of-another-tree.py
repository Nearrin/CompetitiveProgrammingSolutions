# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def same(s,t):
    if not s and not t:
        return True
    if not s or not t:
        return False
    if s.val != t.val:
        return False
    return same(s.left,t.left) and same(s.right,t.right)
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s:
            return False
        return same(s,t) or self.isSubtree(s.left,t) or self.isSubtree(s.right,t)
