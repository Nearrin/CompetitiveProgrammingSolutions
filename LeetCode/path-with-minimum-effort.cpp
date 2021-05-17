class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int emax = 0x3f3f3f3f;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, emax));
        dp[0][0] = 0;
        
        int prev = -1;
        for (int k = 0; k < m*n; k++) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    for (int i = 0; i < 4; i++) {
                        int xn = x + dx[i];
                        int yn = y + dy[i];
                        if (xn < 0 || yn < 0 || xn >= m || yn >= n || dp[x][y] >= dp[xn][yn]) continue;
                        int e = abs(heights[x][y] - heights[xn][yn]);
                        dp[xn][yn] = min(max(dp[x][y], e), dp[xn][yn]); 
                    }
                }
            }
            if (prev == dp[m-1][n-1] && k > max(m, n)) return prev;
            prev = dp[m-1][n-1];
        }
        
        return dp[m-1][n-1];
    }
};
