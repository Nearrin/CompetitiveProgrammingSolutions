class Solution {
public:
    int numberWays(vector<vector<int>>& a) {
        int n=a.size(),m=40;
        vector<vector<int>>b(m);
        for(int i=0;i<n;++i)
            for(auto j:a[i]){
                b[j-1].push_back(i);
            }
        vector<vector<int>>f(m+1,vector<int>(1<<n));
        f[0][0]=1;
        for(int i=0;i<m;++i)
        {
             for(int j=0;j<1<<n;++j)
             {
                 f[i+1][j]+=f[i][j];
                 f[i+1][j]%=int(1e9+7);
                 for(auto k:b[i]){
                     if(!((j>>k)&1)){
                         f[i+1][j+(1<<k)]+=f[i][j];
                         f[i+1][j+(1<<k)]%=int(1e9+7);
                     }
                 }
             }
        }
        return f[m][(1<<n)-1];
    }
};
