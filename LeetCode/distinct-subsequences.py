class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        f=[[-1]*(len(t)+1) for i in range(len(s)+1)]
        for i in range(len(s)+1):
            for j in range(len(t)+1):
                if not i and not j:
                    f[i][j]=1
                elif not i:
                    f[i][j]=0
                elif not j:
                    f[i][j]=1
                elif s[i-1]!=t[j-1]:
                    f[i][j]=f[i-1][j]
                else:
                    f[i][j]=f[i-1][j]+f[i-1][j-1]
        return f[-1][-1]
        
