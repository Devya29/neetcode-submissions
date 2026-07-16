class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int shift = k % n;
        if (shift == 0) {
            return;
        }
        
        // Step 1: Store last 'shift' elements in a temporary array
        vector<int> temp(shift);
        for (int i = 0; i < shift; i++) {
            temp[i] = nums[n - shift + i];
        }
        
        // Step 2: Shift the array to the right by 'shift' positions
        for (int i = n - shift - 1; i >= 0; i--) {
            nums[i + shift] = nums[i];
        }

        // Step 3: Copy elements from temp to the beginning of nums
        for (int i = 0; i < shift; i++) {
            nums[i] = temp[i];
        }
    }
};
