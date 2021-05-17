class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& p, vector<vector<int>>& pairs) {
        int ans=0;
        vector<vector<int>>index(n,vector<int>(n));
        for(int i=0;i<p.size();++i){
            for(int j=0;j<p[i].size();++j){
                index[i][p[i][j]]=j;
            }
        }
        vector<int>p2(n);
        for(auto&t:pairs)p2[t[0]]=t[1],p2[t[1]]=t[0];
        for(int x=0;x<n;++x){
            int t=0;
            for(int u=0;u<n;++u)if(u!=x&&u!=p2[x]){
                int y=p2[x],v=p2[u];
                if(index[x][u]<index[x][y]&&index[u][x]<index[u][v]){
                    t=1;
                }
            }
            ans+=t;
        }
        return ans;
    }
};
