class Solution {
    int f(int i, int j, vector<vector<int>>& triangle,
          vector<vector<int>>& dp) {

        if (dp[i][j] != 1e9)
            return dp[i][j];

        if (i == triangle.size() - 1)
            return dp[i][j] = triangle[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diag = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 1e9));
        return f(0, 0, triangle, dp);
    }
};