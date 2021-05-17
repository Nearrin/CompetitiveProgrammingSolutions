def check(n):
    l=0
    r=n
    if n==0 or n==1:
        return True
    #l*l<n r*r>=n
    while l+1<r:
        m=(l+r)//2
        if m*m<n:
            l=m
        else:
            r=m
    return r*r==n
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        i=0
        while i*i<=c:
            if check(c-i*i):
                return True
            i+=1
        return False
        
