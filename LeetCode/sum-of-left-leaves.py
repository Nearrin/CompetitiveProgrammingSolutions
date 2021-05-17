# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def dfs(x,d):
    if not x:
        return 0
    if x.left or x.right:
        return dfs(x.left,0)+dfs(x.right,1)
    if d==0:
        return x.val
    return 0
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return dfs(root,1)
