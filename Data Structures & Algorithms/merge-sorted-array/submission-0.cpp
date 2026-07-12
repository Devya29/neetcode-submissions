class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums2[j] > nums1[i])
            {
                nums1[k] = nums2[j];
                j--;
            }
            else
            {
                nums1[k] = nums1[i];
                i--;
            }

            k--;
        }

        // Remaining elements of nums2
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // No need to copy remaining nums1 elements.
        // They are already in the correct position.
    }
};