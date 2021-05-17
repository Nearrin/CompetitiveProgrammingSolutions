class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60]={0};
        int ans=0;
        for(int t:time){
            t%=60;
            ans+=cnt[(60-t)%60];
            ++cnt[t];
        }return ans;
    }
};
