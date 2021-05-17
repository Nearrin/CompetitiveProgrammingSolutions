# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def dfs(root,cur,cnt,sum,ans):
    if not root:
        return
    #root.val+cur-x=sum
    ans[0]+=cnt[root.val+cur-sum]
    cnt[root.val+cur]+=1
    dfs(root.left,root.val+cur,cnt,sum,ans)
    dfs(root.right,root.val+cur,cnt,sum,ans)
    cnt[root.val+cur]-=1
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        from collections import defaultdict
        cnt=defaultdict(int)
        cnt[0]=1
        ans=[0]
        dfs(root,0,cnt,sum,ans)
        return ans[0]
