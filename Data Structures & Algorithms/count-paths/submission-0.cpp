class Solution {
public:
    bool check(int i,int j,int m ,int n)
    {
        if(i<m&&j<n)return true;
        return false;
    }
    int solve(int m,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i==m-1&&j==n-1)return 1;
        int down=0,right=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(check(i+1,j,m,n)){
         down=solve(m,n,i+1,j,dp);
        }
        if(check(i,j+1,m,n)){
            right=solve(m,n,i,j+1,dp);
        }
        dp[i][j]=right+down;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solve(m,n,0,0,dp);
        return ans;
    }
};