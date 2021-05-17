# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def dfs(x,v):
    if x:
        dfs(x.left,v)
        v.append(x.val)
        dfs(x.right,v)

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        v=[]
        dfs(root1,v)
        dfs(root2,v)
        return sorted(v)
        
