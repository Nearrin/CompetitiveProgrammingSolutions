class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto&a:grid)for(auto&b:a)ans+=(b<0);
        return ans;
    }
};
