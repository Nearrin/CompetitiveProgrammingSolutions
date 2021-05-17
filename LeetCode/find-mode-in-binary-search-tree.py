# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#how to save space??? do it twice!!!!
#以下是我知识的盲区。。。单次查不需要二分合并信息。。。直接先中序遍历一个个加过去更好写。。。
#class info:
#    def __int__(self,v):
#        self.max_cnt=1
#        self.left_val=v
#        self.left_cnt=1
#        self.right_val=v
#        self.right_cnt=1
#def add(i1,i2):
#
#i3=info(0)
#    i3.max_cnt=max(i1.max_cnt,i2.max_cnt)
#    
#def dfs1(x):
#    i=info(x.val)
#    i.max_info=
#    if x.left:
#        il=dfs1(x.left)
            
            
            
def dfs(x,info):
    if not x:
        return
    dfs(x.left,info)
    if info[2]!=x.val:
        info[2]=x.val
        info[3]=1
    else:
        info[3]+=1
    if info[3]>info[1]:
        info[1]=info[3]
        info[0]=info[2]
    dfs(x.right,info)
def dfs2(x,info,ans):
    if not x:
        return
    dfs2(x.left,info,ans)
    if info[1]!=x.val:
        if info[2]==info[0]:
            ans.append(info[1])
        info[1]=x.val
        info[2]=1
    else:
        info[2]+=1
    dfs2(x.right,info,ans)
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        info=[None,0,None,0]
        dfs(root,info)
        info=[info[1],None,0]
        ans=[]
        dfs2(root,info,ans)
        if info[2]==info[0]:
            ans.append(info[1])
        return ans
        
