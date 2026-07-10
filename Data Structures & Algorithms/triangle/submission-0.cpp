class Solution {
public:
    int solve(vector<vector<int>>&triangle,int c,int r,vector<vector<int>>&dp){
        if(r==triangle.size())return 0;
        if(dp[r][c] != INT_MAX)
    return dp[r][c];
        return dp[r][c]=min(solve(triangle,c+1,r+1,dp),solve(triangle,c,r+1,dp))+triangle[r][c];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(triangle,0,0,dp);
    }
};