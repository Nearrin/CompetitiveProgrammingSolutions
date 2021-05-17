class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g=sorted(g)
        s=sorted(s)
        i=0
        ans=0
        for this_g in g:
            while i<len(s) and s[i]<this_g:
                i+=1
            if i<len(s):
                i+=1
                ans+=1
        return ans
