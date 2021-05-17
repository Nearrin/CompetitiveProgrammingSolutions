class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        t=[]
        d=0
        for u,v in shift:
            d+=(1-u*2)*v
        for i in range(len(s)):
            j=d+i
            j%=len(s)
            j+=len(s)
            j%=len(s)
            t.append(s[j])
        return ''.join(t)
