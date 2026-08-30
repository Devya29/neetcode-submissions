class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&vis)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i])continue;
            temp.push_back(nums[i]);
            vis[i]=true;
            solve(nums,ans,temp,vis);
            temp.pop_back();
            vis[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<bool>flag(nums.size(),false);
        vector<int>temp;
        solve(nums,ans,temp,flag);
        return ans;
    }
};