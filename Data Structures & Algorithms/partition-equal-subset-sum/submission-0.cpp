class Solution {
public:
    bool solve(vector<int>& nums,
               vector<vector<int>>& dp,
               int target,
               int index)
    {
        if (target == 0)
            return true;

        if (index >= nums.size())
            return false;

        if (dp[index][target] != -1)
            return dp[index][target];

        if (nums[index] > target)
        {
            bool exclude = solve(nums, dp, target, index + 1);

            dp[index][target] = exclude;
            return dp[index][target];
        }

        bool include = solve(nums, dp, target - nums[index], index + 1);
        bool exclude = solve(nums, dp, target, index + 1);

        dp[index][target] = include || exclude;

        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(target + 1, -1));

        return solve(nums, dp, target, 0);
    }
};