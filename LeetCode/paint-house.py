class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        f=[(0,3)]
        for i in range(len(costs)):
            g=[]
            for c in range(3):
                for t in f:
                    if t[1]!=c:
                        g.append((t[0]+costs[i][c],c))
            g=sorted(g)
            f=[]
            vis=[0]*3
            for t in g:
                if not vis[t[1]]:
                    f.append(t)
                    vis[t[1]]=1
            f=f[:2]
        return min(f)[0]
            
