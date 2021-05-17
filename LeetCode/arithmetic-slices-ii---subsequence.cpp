class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size(),c=n*(1-n)/2;
        vector<unordered_map<long long,int>>f(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j)
                f[i][0ll+a[i]-a[j]]+=1+f[j][0ll+a[i]-a[j]];
            for(auto j:f[i])c+=j.second;
        }
        return c;
    }
};
