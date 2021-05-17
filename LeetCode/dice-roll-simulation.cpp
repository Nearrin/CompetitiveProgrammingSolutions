class Solution {
public:
    int dieSimulator(int n, vector<int>& a) {
        vector<vector<int>>f(7,vector<int>(16));
        f[0][1]=1;
        while(n--){
            vector<vector<int>>g(7,vector<int>(16));
            for(int i=0;i<=6;++i)
                for(int j=1;j<=15;++j)
                    for(int k=1;k<=6;++k)
                        if((i==k?j+1:1)<=a[k-1])
                            g[k][i==k?j+1:1]+=f[i][j],
                            g[k][i==k?j+1:1]%=int(1e9+7);
            f=g;
        }
        int r=0;
        for(int i=1;i<=6;++i)
            for(int j=1;j<=15;++j)
                r=(r+f[i][j])%int(1e9+7);
        return r;
    }
};
