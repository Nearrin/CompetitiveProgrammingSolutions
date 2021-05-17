class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        // edge cases away
        if (!k || len < 2) return 0;
        // special case of unlimited transactions
        if (len < k * 2) {
            int sum = 0;
            for (int i = 1; i < len; i++) sum += max(0, prices[i] - prices[i - 1]);
            return sum;
        }
        // fixing k to be a meaningful, even number
        k = k * 2;
        // declaring and setting up dp
        int dp[k];
        for (int i = 0; i < k; i++) dp[i] = i % 2 ? 0 : INT_MAX;
        for (int currPrice: prices) {
            // setting up the first dp element
            dp[0] = min(dp[0], currPrice);
            // updating dp with all the subsequent trades
            for (int i = 1; i < k; i++) {
                dp[i] = i % 2 ? max(dp[i], currPrice - dp[i - 1]) : min(dp[i], currPrice - dp[i - 1]);
            }
        }
        return dp[k - 1];
    }
};
