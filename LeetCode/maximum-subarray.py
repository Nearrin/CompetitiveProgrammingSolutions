class Info:
    def __init__(self,ml=None,ms=None,mr=None,s=None):
        self.max_left=ml
        self.max_sub=ms
        self.max_right=mr
        self.sum=s

def merge(i1,i2):
    i3=Info()
    i3.sum=i1.sum+i2.sum
    i3.max_sub=max(i1.max_sub,i2.max_sub,i1.max_right+i2.max_left)
    i3.max_left=max(i1.max_left,i1.sum+i2.max_left)
    i3.max_right=max(i2.max_right,i2.sum+i1.max_right)
    return i3

def work(a,l,r):
    if l==r:
        return Info(a[l],a[l],a[l],a[l])
    m=int((l+r)/2)
    i1=work(a,l,m)
    i2=work(a,m+1,r)
    return merge(i1,i2)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return work(nums,0,len(nums)-1).max_sub
