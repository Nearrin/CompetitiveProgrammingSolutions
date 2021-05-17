def f(n):
    return int(10**n*n-1-10*(10**(n-1)-1)//9)

def get_len(n):
    l_n=len(str(n))
    l=f(l_n-1)
    l+=(n-10**(l_n-1)+1)*l_n;
    return l

class Solution:
    def findNthDigit(self, n: int) -> int:
        #l<=target<r
        l=1
        r=1
        while get_len(r)<=n:
            r*=2
        while l+1!=r:
            m=(l+r)//2
            if get_len(m)<=n:
                l=m
            else:
                r=m
        print(l,r,n)
        if get_len(l)==n:
            return int(str(l)[-1])
        t=n-get_len(l)-1
        return int(str(r)[t])
        
        
        
        
