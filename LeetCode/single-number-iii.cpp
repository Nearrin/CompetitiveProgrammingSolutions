class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>cnt;
        for(auto v:nums)++cnt[v];
        vector<int>ans;
        for(auto v:nums)if(cnt[v]==1)ans.push_back(v);
        return ans;
    }
};
