class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        int ansIndex = arr.size();
        sort(arr.begin(),arr.end());
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == mid) {
                start = mid + 1;
            } else {
                ansIndex = mid;
                end = mid - 1;
            }
        }

        return ansIndex;
    }
};