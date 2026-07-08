class Solution {
public:
    int findmin(vector<int>&nums)
    {
        int sum=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            ans=min(ans,sum);
            if(sum>0)sum=0;
        }
        return ans;
    }
    int findmax(vector<int>&nums)
    {
        int sum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0)sum=0;
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int k = findmax(nums);
        if(k<0)return k;
        int mini=findmin(nums);
        return max((accumulate(nums.begin(),nums.end(),0)-mini),k);
    }
};