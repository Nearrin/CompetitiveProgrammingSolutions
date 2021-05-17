class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        static int e[110][110];
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)e[i][j]=0;
        static int cnt[110];
         for(int i=0;i<n;++i)cnt[i]=0;
        for(auto t:roads){
            e[t[0]][t[1]]=1;
            e[t[1]][t[0]]=1;
            ++cnt[t[0]];
            ++cnt[t[1]];
        }
        int ans=0;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(i!=j)ans=max(ans,cnt[i]+cnt[j]-e[i][j]);
        return ans;
    }
};
