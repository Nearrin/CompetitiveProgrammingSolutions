class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>tmp;
        auto tmp2=nums;
        do{
            tmp.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }while(nums!=tmp2);
        return tmp;
    }
};
