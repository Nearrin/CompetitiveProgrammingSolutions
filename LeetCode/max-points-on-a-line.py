def gcd(a,b):
    return gcd(b,a%b) if b else a

def normalize(v):
    if v[0]<0:
        v=(-v[0],-v[1])
    #Carefull!
    if v[0]==0 and v[1]<0:
        v=(0,-v[1])
    #Carefull!
    if v==(0,0):
        return (0,0)
    g=gcd(v[0],abs(v[1]))
    return (v[0]//g,v[1]//g)

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        from collections import defaultdict
        ans=[]
        for ori in points:
            v=[(i[0]-ori[0],i[1]-ori[1]) for i in points]
            v=map(normalize,v)
            c=defaultdict(int)
            c0=0
            cmax=0
            for i in v:
                if i==(0,0):
                    c0+=1
                else:
                    c[i]+=1
                    t=c[i]
                    if t>cmax:
                        cmax=t
            # Duplicated points are handled!
            ans.append(c0+cmax)
        #Died once!!!!!!!!
        if not ans:
            return 0
        return max(ans)
            
