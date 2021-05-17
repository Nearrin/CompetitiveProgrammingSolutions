class Solution:
    def minInsertions(self, s: str) -> int:
        f=[[-1]*len(s) for i in range(len(s))]
        for l in range(1,len(s)+1):
            for j in range(len(s)-l+1):
                if l==1:
                    f[j][j+l-1]=0
                elif l==2:
                    if s[j]==s[j+1]:
                        f[j][j+l-1]=0
                    else:
                        f[j][j+l-1]=1
                elif s[j]==s[j+l-1]:
                    f[j][j+l-1]=min(f[j+1][j+l-1-1],f[j][j+l-1-1]+1,f[j+1][j+l-1]+1)
                else:
                    f[j][j+l-1]=min(f[j][j+l-1-1]+1,f[j+1][j+l-1]+1)
        return f[0][len(s)-1]
                
                
