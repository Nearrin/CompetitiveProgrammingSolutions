class Solution {
public:
    const int INF = INT_MAX/2;
    int f(const vector<int>& cuts, int i, int j, int s, int e,vector<vector<int>>& dp) {
        if(i>j){
            return 0;
        }
        if(j-i == 0) {
            return e - s;
        } else if(j - i == 1) {
            return e - s + min(cuts[j] - s, e - cuts[i]);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ret = INF;
        for(int m = i;m<=j;m++) {
            int d = e - s + f(cuts,i,m-1,s,cuts[m],dp) + f(cuts,m+1,j,cuts[m],e,dp);
            ret = min(ret,d);
        }
       
        return dp[i][j] = ret;
        
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(100,vector<int>(100,-1));
        return f(cuts,0,cuts.size()-1,0,n,dp);
    }
};
