class Solution {
public:
    int recur(vector<int>& prices, int n, int i, int t, vector<vector<int>>& dp){
        if(i==n || t==0) return 0;
        if(dp[i][t]!=-1) return dp[i][t];

        int ans1= recur(prices, n, i+1, t, dp); 

        int ch=(t%2);

        int ans2=0; 

        if(ch==0){ 
            ans2=-prices[i]+recur(prices, n, i+1, t-1, dp);
        }
        else{
            ans2=prices[i]+recur(prices, n, i+1, t-1, dp);

        }

        return dp[i][t]=max(ans1, ans2);

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (5, -1));
        return recur(prices, n, 0, 4, dp);
    }
};