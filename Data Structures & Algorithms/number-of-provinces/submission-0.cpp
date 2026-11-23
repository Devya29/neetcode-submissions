class Solution {
public:
    void dfs(unordered_map<int, bool>& tracker, int i, int& n,
             vector<vector<int>>& arr) {
        for (int k = 0; k < n; k++) {
            if (k == i - 1)
                continue;
            if (arr[i - 1][k] == 1 && !tracker[k + 1]) {
                tracker[k + 1] = true;
                dfs(tracker, k + 1, n, arr);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, bool> tracker;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!tracker[i]) {
                tracker[i] = true;
                dfs(tracker, i, n, isConnected);
                ans++;
            }
        }
        return ans;
    }
};