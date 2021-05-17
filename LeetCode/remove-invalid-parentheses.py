#这题居然一开始想错了。。。不能两边转移的，要枚举中心TAT
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        # re+1   wo kao!!!!!!!!!!made
        if not s:
            return [""]
        n=len(s)
        f=[[0]*n for i in range(n)]
        g=[[[] for i in range(n)] for j in range(n)]
        for i in range(n-1):
            g[i+1][i].append('')
        for d in range(1,n+1):
            for i in range(0,n-d+1):
                j=i+d-1
                if i==j:
                    f[i][j]=(1 if s[i] in '()' else 0)
                    if s[i] not in '()':
                        g[i][j].append(s[i])
                    else:
                        g[i][j].append('')  #not empty but empty string!!!
                elif s[i] not in '()':
                    f[i][j]=f[i+1][j]
                    g[i][j]=[s[i]+t for t in g[i+1][j]]
                elif s[j] not in '()':
                    f[i][j]=f[i][j-1]
                    g[i][j]=[t+s[j]for t in g[i][j-1]]
                else:
                    f[i][j]=n+1
                    if s[i]=='(' and s[j]==')':
                        f[i][j]=min(f[i][j],f[i+1][j-1])# won't out of boundary
                    for k in range(i,j):
                        f[i][j]=min(f[i][j],f[i][k]+f[k+1][j])
                    if s[i]=='(' and s[j]==')' and f[i][j]==f[i+1][j-1]:
                        for t in g[i+1][j-1]:
                            g[i][j].append('('+t+')')
                    for k in range(i,j):
                        if f[i][j]==f[i][k]+f[k+1][j]:
                            for t1 in g[i][k]:
                                for t2 in g[k+1][j]:
                                    g[i][j].append(t1+t2)
                    g[i][j]=set(g[i][j])
                #print(s[i:j+1],list(g[i][j]),f[i][j])
        return list(g[0][n-1])
        
        
        
