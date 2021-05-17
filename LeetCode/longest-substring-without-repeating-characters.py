class Table:
    def __init__(self):
        self.t={}
        self.v_cnt=0
    def add(self,a):
        if a not in self.t or self.t[a]==0:
            self.t[a]=1
        elif self.t[a]==1:
            self.t[a]+=1
            self.v_cnt+=1
        else:
            self.t[a]+=1
    def remove(self,a):
        if self.t[a]==1:
            self.t[a]-=1
        elif self.t[a]==2:
            self.t[a]-=1
            self.v_cnt-=1
        else:
            self.t[a]-=1
    def valid(self):
        return not self.v_cnt

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l=0
        t=Table()
        res=[]
        for r in range(len(s)):
            t.add(s[r])
            while not t.valid():
                t.remove(s[l])
                l+=1
            res.append(r-l+1)
        return max([0]+res)
            
            
