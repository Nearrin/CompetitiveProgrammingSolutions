struct ufs{
    ufs(int n):p(n){
        for(int i=0;i<n;++i)p[i]=i;
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    void link(int x,int y){
        if(find(x)!=find(y))
        p[find(x)]=y;
    }
    vector<int>p;
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        ufs bfs(n*m);
        unordered_set<char>has[7];
        has[1].insert('L');
        has[1].insert('R');
        has[2].insert('U');
        has[2].insert('D');
        has[3].insert('L');
        has[3].insert('D');
        has[4].insert('R');
        has[4].insert('D');
        has[5].insert('U');
        has[5].insert('L');
        has[6].insert('U');
        has[6].insert('R');
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                static int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                static char*s="UDRL";
                for(int k=0;k<4;++k){
                    int ni=i+d[k][0],nj=j+d[k][1];
                    if(ni>=0&&ni<n&&nj>=0&&nj<m){
                        if(s[k]=='U'&&has[a[ni][nj]].count('D')&&has[a[i][j]].count('U'))
                            bfs.link(ni*m+nj,i*m+j);
                        if(s[k]=='D'&&has[a[ni][nj]].count('U')&&has[a[i][j]].count('D'))
                            bfs.link(ni*m+nj,i*m+j);
                        if(s[k]=='L'&&has[a[ni][nj]].count('R')&&has[a[i][j]].count('L'))
                            bfs.link(ni*m+nj,i*m+j);
                        if(s[k]=='R'&&has[a[ni][nj]].count('L')&&has[a[i][j]].count('R'))
                            bfs.link(ni*m+nj,i*m+j);
                    }
                }
            }
        }
        return(bfs.find(n*m-1)==bfs.find(0));
    }
};
