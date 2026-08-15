class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>tracker;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            tracker[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(tracker[nums[i]]>(nums.size()/2)){
                ans=max(ans, nums[i]);
            }
        }
        return ans;
    }
};