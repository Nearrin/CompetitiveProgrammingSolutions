# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def dfs(x,ans):
    if not x.left and not x.right:
        return (x.val,x.val)
    mi=x.val
    mx=x.val
    if x.left:
        t=dfs(x.left,ans)
        ans.append(x.val-t[1])
        mi=t[0]
    if x.right:
        t=dfs(x.right,ans)
        ans.append(-x.val+t[0])
        mx=t[1]
    return (mi,mx)

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        ans=[]
        dfs(root,ans)
        return min(ans)
        
