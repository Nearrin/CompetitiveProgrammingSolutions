class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>f;
        for(auto v:arr)++f[v];
        int ans=-1;
        for(auto v:arr)if(v==f[v])ans=max(ans,v);
        return ans;
    }
};
