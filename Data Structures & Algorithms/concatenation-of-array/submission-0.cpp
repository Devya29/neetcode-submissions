class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // int k=nums.size();
        // int j=0;
        // for(int i=(k-1);i<(2*k);k++)
        // {
        //     nums.push_back(nums[j]);
        //     j++;
        // }
        // return nums;
        vector<int>ans=nums;
        int k=nums.size();
        int j=0;
        for(int i=(k);i<(2*k);i++)
        {
            ans.push_back(nums[j]);
            j++;
        }
    return ans;
    }
};