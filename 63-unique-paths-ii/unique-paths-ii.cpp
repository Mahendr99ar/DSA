class Solution {
public:
    void solve(vector<vector<long long>>& dp, vector<vector<int>>& grid, int i,
               int j) {
        if (i >= grid.size()) {
            return;
        }
        if (j >= grid[0].size()) {
            solve(dp, grid, i + 1, 0);
            return;
        }
        if (dp[i][j] != -1 && (i != 0 || j != 0)) {
            return;
        }
        if (grid[i][j] == 1) {
            dp[i][j] = 0;
            solve(dp, grid, i, j+1);
            return;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = 0;
        }
        if (i > 0)
            dp[i][j] += dp[i - 1][j];

        if (j > 0)
            dp[i][j] += dp[i][j - 1];

        solve(dp, grid, i, j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        dp[0][0] = 1;
        solve(dp, obstacleGrid, 0, 0);
        return dp[m - 1][n - 1];
    }
};