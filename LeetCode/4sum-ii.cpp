class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans=0;
        unordered_map<int,int>cnt;
        for(auto a:A)for(auto b:B)++cnt[a+b];
        for(auto c:C)for(auto d:D)ans+=cnt[-c-d];
        return ans;
    }
};
