# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if not root:
            return root
        if not root.left and not root.right:
            if root.val==target:
                return None
            return root
        root.left=self.removeLeafNodes(root.left,target)
        root.right=self.removeLeafNodes(root.right,target)
        if not root.left and not root.right:
            if root.val==target:
                return None
            return root
        return root
