class Solution {
public:

    bool check(int i, int j, int m, int n,
               vector<vector<int>>& dp)
    {
        if(i < m && j < n && dp[i][j] != 0)
            return true;

        return false;
    }

    int solve(int m, int n, int i, int j,
              vector<vector<int>>& dp)
    {
        if(i == m - 1 && j == n - 1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = 0, right = 0;

        if(check(i + 1, j, m, n, dp))
            down = solve(m, n, i + 1, j, dp);

        if(check(i, j + 1, m, n, dp))
            right = solve(m, n, i, j + 1, dp);

        dp[i][j] = down + right;

        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Mark obstacles as 0
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
            }
        }

        if(dp[0][0] == 0 || dp[m-1][n-1] == 0)
            return 0;

        return solve(m, n, 0, 0, dp);
    }
};