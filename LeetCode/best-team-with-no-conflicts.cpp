class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>a;
        for(int i=0;i<scores.size();++i)
            a.push_back({scores[i],ages[i]});
        sort(begin(a),end(a));
        vector<int>dp(a.size(),0);
        for(int i=0;i<a.size();++i){
            dp[i]=a[i].first;
            for(int j=0;j<i;++j){
                if(a[j].first==a[i].first){
                    dp[i]=max(dp[i],dp[j]+a[i].first);
                }else if(a[j].second<=a[i].second){
                    dp[i]=max(dp[i],dp[j]+a[i].first);
                }
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};
