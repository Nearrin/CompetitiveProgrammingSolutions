# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def dfs(u,pval,dep,tb):
    if not u:
        return
    tb[u.val]=(dep,pval)
    dfs(u.left,u.val,dep+1,tb)
    dfs(u.right,u.val,dep+1,tb)
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        t={}
        dfs(root,-1,0,t)
        return t[x][0]==t[y][0]and t[x][1]!=t[y][1]
