# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p==root or q== root:
            return root
        if p.val<root.val and q.val<root.val or p.val>root.val and q.val>root.val:
            return self.lowestCommonAncestor(root.left if p.val<root.val else root.right,p,q)
        return root
