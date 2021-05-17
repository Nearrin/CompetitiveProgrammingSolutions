class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>c;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                c[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto&[k,v]:c){
            ans+=v*(v-1)*4;
        }
        return ans;
    }
};
