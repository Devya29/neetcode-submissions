class Solution {
public:
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>>& dp)
    {
        if (j >= w2.length())
            return w1.length() - i;

        if (i >= w1.length())
            return w2.length() - j;

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int ans = 0;

        if (w1[i] == w2[j])
        {
            ans = solve(w1, w2, i + 1, j + 1, dp);
        }
        else
        {
            int insert = 1 + solve(w1, w2, i, j + 1, dp);
            int delete_ = 1 + solve(w1, w2, i + 1, j, dp);
            int replace = 1 + solve(w1, w2, i + 1, j + 1, dp);

            ans = min({insert, delete_, replace});
        }

        dp[i][j] = ans;
        return ans;
    }

    int minDistance(string word1, string word2)
    {
        int i = 0, j = 0;

        vector<vector<int>> dp(
            word1.length()+1,
            vector<int>(word2.length()+1, INT_MAX)
        );

        return solve(word1, word2, i, j, dp);
    }
};