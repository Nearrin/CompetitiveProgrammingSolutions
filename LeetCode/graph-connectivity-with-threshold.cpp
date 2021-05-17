class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int>p(n);
        for(int i=0;i<n;++i)p[i]=i;
        function<int(int)> fd=[&](int u){
            return p[u]==u?u:p[u]=fd(p[u]);
        };
        auto lk=[&](int u,int v){
            p[fd(u)]=v;
        };
        for(int i=threshold+1;i<=n;i+=1){
            for(int j=i+i;j<=n;j+=i){
                if(fd(i-1)!=fd(j-1)){
                    lk(i-1,j-1);
                }
            }
        }
        vector<bool>ans;
        for(auto&t:queries)ans.push_back(fd(t[0]-1)==fd(t[1]-1));
        return ans;
    }
};
