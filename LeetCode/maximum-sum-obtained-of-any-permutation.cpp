class Solution {
public:
    int maxSumRangeQuery(vector<int>& a, vector<vector<int>>& r) {
        int n=a.size();
        vector<int>t(n);
        for(auto&v:r){
            int x=v[0],y=v[1];
            t[x]++;
            if(y!=n-1)
                t[y+1]--;
        }
        for(int i=1;i<n;++i)t[i]+=t[i-1];
        sort(begin(t),end(t));
        sort(begin(a),end(a));
        long long ans=0;
        for(int i=0;i<n;++i){
            ans+=(long long)t[i]*a[i];
        }
        return ans%int(1e9+7);
    }
};
