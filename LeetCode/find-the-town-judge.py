class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        a=[0]*(N+1)
        b=[0]*(N+1)
        for u,v in trust:
            a[v]+=1
            b[u]+=1
        c=[i for i in range(1,N+1) if b[i]==0 and a[i]==N-1]
        if len(c)==1:
            return c[0]
        return -1
        
