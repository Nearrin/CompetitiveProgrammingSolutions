class Solution:
    def maximumProduct(self, a: List[int]) -> int:
        b=[[],[],[]]
        for v in a:
            b[1 if v==0 else (0 if v>0 else 2)].append(v)
        b[0]=[sorted(b[0]),sorted(b[0])[::-1]]
        b[2]=[sorted(b[2]),sorted(b[2])[::-1]]
        c=float('-inf')
        for i in [0,1]:
            for j in [0,1,2,3]:
                if len(b[0][i])<j:
                    continue;
                for k in [0,1]:
                    for l in range(0,3-j+1):
                        if len(b[2][k])<l:
                            continue
                        m=3-j-l
                        if len(b[1])>=m:
                            c=max(c,functools.reduce(lambda x,y:x*y,b[0][i][:j]+b[2][k][:l]+b[1][:m]))
        return c
