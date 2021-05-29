class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=nums.front()+nums.back();
        for(int i=0;i<nums.size();++i){
            ans=max(ans,nums[i]+nums[nums.size()-i-1]);
        }
        return ans;
    }
};
