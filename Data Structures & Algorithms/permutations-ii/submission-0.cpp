class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp,
               vector<int>& res, vector<bool>& vis)
    {
        if(res.size() == temp.size())
        {
            ans.push_back(res);
            return;
        }

        for(int i = 0; i < temp.size(); i++)
        {
            if(vis[i])
                continue;

            if(i > 0 && temp[i] == temp[i - 1] && !vis[i - 1])
                continue;

            vis[i] = true;
            res.push_back(temp[i]);

            solve(ans, temp, res, vis);

            res.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> vis(nums.size(), false);

        solve(ans, nums, res, vis);

        return ans;
    }
};