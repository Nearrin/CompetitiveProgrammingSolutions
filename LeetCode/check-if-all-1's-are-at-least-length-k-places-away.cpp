class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>a;
        for(int i=0;i<nums.size();++i){
            if(nums[i]){
                if(a.size()&&i-a.back()-1<k)
                    return 0;
                a.push_back(i);
            }
        }
        return 1;
    }
};
