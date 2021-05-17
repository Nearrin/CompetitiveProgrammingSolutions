class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int t=0;
        for(auto v:nums)t=(t+v)%p;
        if(t==0)return 0;
        unordered_map<int,int>pos;
        pos[0]=-1;
        int cur=0;
        int ans=nums.size();
        for(int i=0;i<nums.size();++i){
            cur=(cur+nums[i])%p;
            int t2=cur-t;
            t2=(t2%p+p)%p;
            if(pos.count(t2))
                ans=min(ans,i-pos[t2]);
            pos[cur]=i;
        }
        if(ans==nums.size())return -1;
        return ans;
    }
};
