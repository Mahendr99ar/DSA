class Solution {

    int help(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        if (i + 1 == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;

        for (int k = i + 1; k < j; k++) {

            int points = nums[i] * nums[k] * nums[j]
                       + help(i, k, nums, dp)
                       + help(k, j, nums, dp);

            maxi = max(maxi, points);
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return help(0, n - 1, nums, dp);
    }
};