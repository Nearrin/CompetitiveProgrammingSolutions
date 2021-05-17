class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int ans=1;
        vector<unordered_map<int,int>>f(a.size());
        for(int i=0;i<a.size();++i){
            for(int j=0;j<i;++j){
                int d=a[i]-a[j];
                if(f[j].count(d))
                    f[i][d]=f[j][d]+1;
                else
                    f[i][d]=2;
                ans=max(ans,f[i][d]);
            }
        }
        return ans;
    }
};
