class Solution:
    def numWays(self, n: int, k: int) -> int:
        same=[0]*(n+3)
        diff=[0]*(n+3)
        same[1]=0
        diff[1]=k
        same[2]=k
        diff[2]=k*(k-1)
        for i in range(3,n+1):
            same[i]=(k-1)*(diff[i-2]+same[i-2])
            diff[i]=(k-1)*(same[i-1]+diff[i-1])
        return same[n]+diff[n]
