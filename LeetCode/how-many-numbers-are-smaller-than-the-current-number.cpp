class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();++i){
            ans.push_back(0);
            for(int j=0;j<nums.size();++j)if(nums[i]>nums[j])++ans.back();
        }
        return ans;
    }
};
