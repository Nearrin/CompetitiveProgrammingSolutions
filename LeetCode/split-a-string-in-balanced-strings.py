class Solution:
    def balancedStringSplit(self, s: str) -> int:
        t=0
        ans=0
        for c in s:
            t+=1 if c=='L'else -1
            if not t:
                ans+=1
        return ans
