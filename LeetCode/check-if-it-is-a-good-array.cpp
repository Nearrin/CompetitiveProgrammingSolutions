class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int ans=0;
        for(int v:nums)ans=gcd(ans,v);
        return ans==1;
    }
};
