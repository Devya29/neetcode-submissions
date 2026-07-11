class Solution {
public:
    int solve(vector<int>& coins, int amt, vector<int>& dp)
    {
        // Base Case
        if (amt == 0)
            return 0;

        // DP Check
        if (dp[amt] != -1)
            return dp[amt];

        int mini = INT_MAX;

        for (int coin : coins)
        {
            if (coin <= amt)
            {
                int ans = solve(coins, amt - coin, dp);

                // Impossible path ko ignore karo
                if (ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }

        return dp[amt] = mini;
    }

    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};