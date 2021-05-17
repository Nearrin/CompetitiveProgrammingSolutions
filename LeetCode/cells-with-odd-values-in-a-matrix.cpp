class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans=0;
        map<pair<int,int>,int>a;
        for(auto t:indices){
            for(int i=0;i<n;++i)
                ans+=(++a[{i,t[1]}])%2*2-1;
            for(int i=0;i<m;++i)
                ans+=(++a[{t[0],i}])%2*2-1;
        }
        return ans;
    }
};
