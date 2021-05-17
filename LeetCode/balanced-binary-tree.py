# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def check(x):
    if not x:
        return (True,0)
    cl=check(x.left)
    cr=check(x.right)
    if not cl[0] or not cr[0]:
        return (False,-1)
    if abs(cl[1]-cr[1])>1:
        return (False,-1)
    return (True,max(cl[1],cr[1])+1)
    

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return check(root)[0]
        
