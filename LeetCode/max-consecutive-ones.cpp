class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(!nums[i])continue;
            int j=i;
            while(j+1<nums.size()&&nums[j+1])++j;
            ans=max(ans,j-i+1);
            i=j;
        }
        return ans;
    }
};
