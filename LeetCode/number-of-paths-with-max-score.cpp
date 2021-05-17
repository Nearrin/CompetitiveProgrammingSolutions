#include<algorithm>
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int m=board[0].size();
        int MOD=1000000007;
        int NINF=-(~0u>>1);
        vector<vector<int>>f(n,vector<int>(m));
        vector<vector<int>>g=f;
        board[n-1][m-1]='0';
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                if(i+j==0){
                    f[i][j]=0;
                    g[i][j]=1;
                }else if(board[i][j]=='X'){
                    f[i][j]=NINF;   
                }else{
                    f[i][j]=NINF;
                    if(j-1>=0&&f[i][j-1]!=NINF)
                        f[i][j]=max(f[i][j],f[i][j-1]+(board[i][j]-'0'));
                    if(i-1>=0&&f[i-1][j]!=NINF)
                        f[i][j]=max(f[i][j],f[i-1][j]+(board[i][j]-'0'));
                    if(i-1>=0&&j-1>=0&&f[i-1][j-1]!=NINF)
                        f[i][j]=max(f[i][j],f[i-1][j-1]+(board[i][j]-'0'));
                    if(j-1>=0&&f[i][j-1]!=NINF)
                        if(f[i][j]==f[i][j-1]+(board[i][j]-'0'))
                            g[i][j]=(g[i][j]+g[i][j-1])%MOD;
                    if(i-1>=0&&f[i-1][j]!=NINF)
                        if(f[i][j]==f[i-1][j]+(board[i][j]-'0'))
                            g[i][j]=(g[i][j]+g[i-1][j])%MOD;
                    if(i-1>=0&&j-1>=0&&f[i-1][j-1]!=NINF)
                        if(f[i][j]==f[i-1][j-1]+(board[i][j]-'0'))
                            g[i][j]=(g[i][j]+g[i-1][j-1])%MOD;
                }
            }
        if(f[n-1][m-1]==NINF)
            f[n-1][m-1]=0;
        return vector<int>{f[n-1][m-1],g[n-1][m-1]};
    }
};
