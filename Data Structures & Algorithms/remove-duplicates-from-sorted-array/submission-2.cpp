class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int i=0,j=1;
     int n=nums.size();
     while(j<n)
     {
        if(nums[i]==nums[j])j++;
        else 
        nums[++i]=nums[j++];
       if(j<n&&nums[j]<nums[i])return i+1;
     }
     return i+1;
    }
    
};