class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001>f(1);
        for(int v:nums)f=f|(f<<v);
        int s=accumulate(begin(nums),end(nums),0);
        return f[s/2]&&s%2==0;
    }
};
