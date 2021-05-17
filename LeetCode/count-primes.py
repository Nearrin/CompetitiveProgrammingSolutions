class Solution:
    def countPrimes(self, n: int) -> int:
        if n==0:
            return 0
        is_p=[1]*(n+1)
        is_p[0]=0
        is_p[1]=0
        for i in range(2,n+1):
            if is_p[i] and i*i<=n:
                j=i+i
                while j<=n:
                    is_p[j]=0
                    j+=i
        return sum(is_p[:-1],start=0)
        
