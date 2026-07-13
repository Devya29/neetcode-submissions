class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        // int n = row * col;
         int s = 0 ; //, e = n - 1;
         int e=col*(row-1)+(col-1);
        int rowin, colin, mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            rowin = mid / col;
            colin = mid % col;
            if (matrix[rowin][colin] == target)
                return true;
            else if (matrix[rowin][colin] > target)
                e=mid-1;
            else
                s=mid+1;
        }
        return false;
    }
};