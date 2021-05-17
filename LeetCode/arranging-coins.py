def f(n):
    return n*(n+1)//2
class Solution:
    def arrangeCoins(self, n: int) -> int:
        if n==0:
            return 0
        l=1#f(l)<=n
        r=1
        while f(r)<=n:
            r*=2
        while l+1<r:
            m=(l+r)//2
            if f(m)<=n:
                l=m
            else:
                r=m
        return l
        
