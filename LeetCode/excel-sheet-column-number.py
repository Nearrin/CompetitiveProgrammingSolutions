class Solution:
    def titleToNumber(self, s: str) -> int:
        if len(s)==1:
            return ord(s[0])-ord('A')+1
        ans=0
        for i in range(1,len(s)):
            ans+=26**i
        ans+=(ord(s[0])-ord('A'))*26**(len(s)-1)
        #t = cnt len-1 ge A
        t=sum(26**i for i in range(len(s)-1))
        ans+=self.titleToNumber(s[1:])-t+1
        return ans
