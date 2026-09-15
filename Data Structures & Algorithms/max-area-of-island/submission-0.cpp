class Solution {
public:
    bool exploreable(vector<vector<int>>&grid,int i,int j){
        if(i<0||j<0)return false;
        if(i<grid.size()&&j<grid[0].size()&&grid[i][j]==1)return true;
        return false;
    }
    void bfs(vector<vector<int>>&grid,int i,int j,int &area)
    {
        int temparea=0;
        queue<pair<int,int>>cells;
        cells.push({i,j});
        while(!cells.empty())
        {
            int i=cells.front().first;
            int j=cells.front().second;
             cells.pop();
             temparea++;
        //UP
        if(exploreable(grid,i-1,j)){
           cells.push({i-1,j});
           grid[i-1][j]=0;
        }
        //RIGHT
        if(exploreable(grid,i,j+1)){
           cells.push({i,j+1});
           grid[i][j+1]=0;
        }
        //LEFT
        if(exploreable(grid,i,j-1)){
            cells.push({i,j-1});
            grid[i][j-1]=0;
        }
        //DOWN
        if(exploreable(grid,i+1,j)){
             cells.push({i+1,j});
            grid[i+1][j]=0;
        }
    }
    area=max(area,temparea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int zeroflag=0;
        int area=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    zeroflag=1;
                    break;
                }
            }
        }
        if(!zeroflag)
        {
            return 0;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    bfs(grid,i,j,area);
                }
            }
        }
        return area;
    }
};
