# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def dfs(u):
    if not u:
        return 0,0
    sl,dl=dfs(u.left)
    sr,dr=dfs(u.right)
    return sl+sr+u.val,dl+dr+abs(sl-sr)
    
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        return dfs(root)[1]
