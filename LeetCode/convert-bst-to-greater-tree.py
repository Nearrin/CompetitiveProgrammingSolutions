# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def dfs(u,d):
    if not u:
        return 0
    sr=dfs(u.right,d)
    sl=dfs(u.left,d+sr+u.val)
    s=sl+sr+u.val
    u.val+=d+sr
    return s
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        dfs(root,0)
        return root
