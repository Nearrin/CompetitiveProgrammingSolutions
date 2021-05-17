class Solution:
    def printVertically(self, s: str) -> List[str]:
        s=s.split()
        num_rows=max(map(len,s))
        num_cols=len(s)
        ans=[[' ']*num_cols for i in range(num_rows)]
        for i in range(len(s)):
            for j in range(len(s[i])):
                ans[j][i]=s[i][j]
        for i in range(len(ans)):
            ans[i]=''.join(ans[i]).rstrip()
        return ans
        
