def par(i):
    i=i+1
    i+=(i&-i)
    return i-1

def pre(i):
    i=i+1
    i-=(i&-i)
    return i-1

class NumArray:
    def __init__(self, nums: List[int]):
        import copy
        self.a=copy.deepcopy(nums)
        self.s=copy.deepcopy(self.a)
        self.n=len(self.a)
        #O(n) build tree
        for i in range(self.n):
            if par(i)<self.n:
                self.s[par(i)]+=self.s[i]

    def update(self, i: int, val: int) -> None:
        d=val-self.a[i]
        self.a[i]=val
        while i<self.n:
            self.s[i]+=d
            i=par(i)
        
    def sumRange2(self, i):
        r=0
        while i>=0:
            r+=self.s[i]
            i=pre(i)
        return r
        
    def sumRange(self, i: int, j: int) -> int:
        return self.sumRange2(j)-self.sumRange2(i-1)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
