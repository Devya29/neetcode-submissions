// class Solution {
// public:
//     void dfs(unordered_map<int, bool>& tracker, int i, int& n,
//              vector<vector<int>>& arr) {
//         for (int k = 0; k < n; k++) {
//             if (k == i - 1)
//                 continue;
//             if (arr[i - 1][k] == 1 && !tracker[k + 1]) {
//                 tracker[k + 1] = true;
//                 dfs(tracker, k + 1, n, arr);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         unordered_map<int, bool> tracker;
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             if (!tracker[i]) {
//                 tracker[i] = true;
//                 dfs(tracker, i, n, isConnected);
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

// APPROACH 2 ========================================== Optimized
class Solution {
   public:
    void dfs(int i, int& n, vector<vector<int>>& arr) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                arr[i][j] = 0;
                continue;
            } else if (arr[i][j] == -2) {
                arr[i][j] = 0;
                continue;
            } else if ((arr[i][j] == -1) || arr[i][j] == 1) {
                if (arr[j][0] != 0) {
                    arr[i][j] = 0;
                    arr[j][0] = 0;
                    dfs(j, n, arr);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (isConnected[i][0] == 1) {
                isConnected[i][0] = -1;  // Connected and not visited
            } else {
                isConnected[i][0] = -2;  // Not connected and not visited
            }
        }
        for (int i = 0; i < n; i++) {
            if (isConnected[i][0] < 0) {
                dfs(i, n, isConnected);
                ans++;
            }
        }
        return ans;
    }
};