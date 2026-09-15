class Solution {
public:
    bool exploreable(vector<vector<int>>& grid, int i, int j, int prev) {
        if (i < 0 || j < 0)
            return false;
        if (i < grid.size() && j < grid[0].size() && grid[i][j] == prev)
            return true;
        return false;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev=image[sr][sc];
        if(prev==color)return;
        queue<pair<int, int>> spread;
        spread.push({sr, sc});
        image[sr][sc] = color;
        while (!spread.empty()) {
            int i = spread.front().first, j = spread.front().second;
            spread.pop();
            // UP
            if (exploreable(image, i - 1, j, prev)) {
                spread.push({i - 1, j});
                image[i - 1][j] = color;
            }
            // RIGHT
            if (exploreable(image, i, j + 1, prev)) {
                spread.push({i, j + 1});
                image[i][j + 1] = color;
            }
            // LEFT
            if (exploreable(image, i, j - 1, prev)) {
                spread.push({i, j - 1});
                image[i][j - 1] = color;
            }
            // DOWN
            if (exploreable(image, i + 1, j, prev)) {
                spread.push({i + 1, j});
                image[i + 1][j] = color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int r = image.size();
        int c = image[0].size();
        if(image[sr][sc]==color)return image;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = image[i][j];
            }
        }
        bfs(ans, sr, sc, color);
        return ans;
    }
};