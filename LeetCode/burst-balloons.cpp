class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
        vector<int>b(n+2,1);
        for(int i=1;i<=n;++i)b[i]=a[i-1];
        vector<vector<int>>f(n+2,vector<int>(n+2));
        for(int d=1;d<=n;++d)
            for(int i=1;i+d-1<=n;++i){
                int j=i+d-1;
                for(int k=i;k<=j;++k)
                    f[i][j]=max(f[i][j],b[i-1]*b[j+1]*b[k]+f[i][k-1]+f[k+1][j]);
            }
        return f[1][n];
    }
};
