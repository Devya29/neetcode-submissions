class Solution {
public:
    bool exploreable(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0)
            return false;
        if (i < grid.size() && j < grid[0].size() && grid[i][j] == 1)
            return true;
        return false;
    }

    int bfs(vector<vector<int>>& grid,
            queue<pair<int, int>>& rotten) {

        int minutes = 0;

        while (!rotten.empty()) {
            int newlen = rotten.size();
            for (int d = 0; d < newlen; d++) {
               int i = rotten.front().first;
               int j = rotten.front().second;
                rotten.pop();
               
                    // UP
                    if (exploreable(grid, i - 1, j)) {
                        rotten.push({i - 1, j});
                        grid[i - 1][j] = 2;
                    }

                    // RIGHT
                    if (exploreable(grid, i, j + 1)) {
                        rotten.push({i, j + 1});
                        grid[i][j + 1] = 2;
                    }

                    // LEFT
                    if (exploreable(grid, i, j - 1)) {
                        rotten.push({i, j - 1});
                        grid[i][j - 1] = 2;
                    }

                    // DOWN
                    if (exploreable(grid, i + 1, j)) {
                        rotten.push({i + 1, j});
                        grid[i + 1][j] = 2;
                    }
                
            }
            minutes++;
        }

        return minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        queue<pair<int, int>> rotten;
        int r=grid.size(),c=grid[0].size();
        int zeroflag=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0){
                    zeroflag=1;
                    break;
                };
            }
        }
        if(!zeroflag)return 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }
       
    minutes+= bfs(grid,rotten);
                
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return minutes-1;
    }
};