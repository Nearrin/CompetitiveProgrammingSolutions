# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        if not root:
            self.stk=[]
            self.cur=None
            return
        self.stk=[root]
        self.cur=root
        while self.cur.left:
            self.stk.append(self.cur.left)
            self.cur=self.cur.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        rt=self.cur.val
        if self.cur.right:
            self.cur=self.cur.right
            self.stk.append(self.cur)
            while self.cur.left:
                self.stk.append(self.cur.left)
                self.cur=self.cur.left
        else:
            while len(self.stk)!=1 and id(self.stk[-2].right)==id(self.stk[-1]):
                self.stk.pop(-1)
            if len(self.stk)==1:
                self.cur=None
                self.stk=[]
            else:
                self.stk.pop(-1)
                self.cur=self.stk[-1]
                
        return rt
            
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.cur
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
