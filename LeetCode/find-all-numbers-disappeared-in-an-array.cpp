class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int>s;
        for(auto v:nums)s.insert(v);
        vector<int>ans;
        for(int i=1;i<=nums.size();++i)if(!s.count(i))ans.push_back(i);
        return ans;
    }
};
