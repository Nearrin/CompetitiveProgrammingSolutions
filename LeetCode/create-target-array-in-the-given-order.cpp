class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>a;
        for(int i=0;i<nums.size();++i)
            a.insert(index[i]+a.begin(),nums[i]);
        return a;
    }
};
