class Solution {
public:
    bool exploreable(vector<vector<int>>& grid,
                     vector<vector<int>>& tracker,
                     int i, int j)
    {
        if(i < 0 || j < 0)
            return false;

        if(i < grid.size() &&
           j < grid[0].size() &&
           grid[i][j] == 0 &&
           tracker[i][j] == -1)
            return true;

        return false;
    }

    int bfs(vector<vector<int>>& grid,
            vector<vector<int>>& tracker,
            queue<pair<int,int>>& path)
    {
        int level = 1;

        while(!path.empty())
        {
            int len = path.size();

            for(int k = 0; k < len; k++)
            {
                int i = path.front().first;
                int j = path.front().second;
                path.pop();

                if(i == grid.size()-1 && j == grid[0].size()-1)
                    return level;

                // UP
                if(exploreable(grid, tracker, i-1, j))
                {
                    tracker[i-1][j] = level + 1;
                    path.push({i-1,j});
                }

                // RIGHT
                if(exploreable(grid, tracker, i, j+1))
                {
                    tracker[i][j+1] = level + 1;
                    path.push({i,j+1});
                }

                // LEFT
                if(exploreable(grid, tracker, i, j-1))
                {
                    tracker[i][j-1] = level + 1;
                    path.push({i,j-1});
                }

                // DOWN
                if(exploreable(grid, tracker, i+1, j))
                {
                    tracker[i+1][j] = level + 1;
                    path.push({i+1,j});
                }

                // UP-RIGHT
                if(exploreable(grid, tracker, i-1, j+1))
                {
                    tracker[i-1][j+1] = level + 1;
                    path.push({i-1,j+1});
                }

                // UP-LEFT
                if(exploreable(grid, tracker, i-1, j-1))
                {
                    tracker[i-1][j-1] = level + 1;
                    path.push({i-1,j-1});
                }

                // DOWN-RIGHT
                if(exploreable(grid, tracker, i+1, j+1))
                {
                    tracker[i+1][j+1] = level + 1;
                    path.push({i+1,j+1});
                }

                // DOWN-LEFT
                if(exploreable(grid, tracker, i+1, j-1))
                {
                    tracker[i+1][j-1] = level + 1;
                    path.push({i+1,j-1});
                }
            }

            level++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        if(grid[0][0] == 1 || grid[r-1][c-1] == 1)
            return -1;

        if(r == 1)
            return 1;

        vector<vector<int>> tracker(r, vector<int>(c, -1));

        queue<pair<int,int>> path;

        path.push({0,0});
        tracker[0][0] = 1;

        return bfs(grid, tracker, path);
    }
};