class Solution {
   public:
    int exploreable(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0||i>grid.size()-1||j>grid[0].size()-1) return 2;
        if (i < grid.size() && j < grid[0].size() && grid[i][j] == 1) return 1;
        return 0;
    }
    int bfs(vector<vector<int>>& grid, int i, int j)
    {
        int area=0;
        queue<pair<int,int>>cells;
        cells.push({i,j});
        bool bahar=false;
        while(!cells.empty())
        {
            int i=cells.front().first;
            int j=cells.front().second;
             cells.pop();
             area++;
        //UP
        if(exploreable(grid,i-1,j)==1){
           cells.push({i-1,j});
           grid[i-1][j]=0;
        }else if(exploreable(grid,i-1,j)==2)bahar=true;
        //RIGHT
        if(exploreable(grid,i,j+1)==1){
           cells.push({i,j+1});
           grid[i][j+1]=0;
        }else if(exploreable(grid,i,j+1)==2)bahar=true;
        //LEFT
        if(exploreable(grid,i,j-1)==1){
            cells.push({i,j-1});
            grid[i][j-1]=0;
        }else if(exploreable(grid,i,j-1)==2)bahar=true;
        //DOWN
        if(exploreable(grid,i+1,j)==1){
             cells.push({i+1,j});
            grid[i+1][j]=0;
        }else if(exploreable(grid,i+1,j)==2)bahar=true;
    }
    if(bahar)return 0;
    return area;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int zeroflag=0;
        int area=0;
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
                    int newa =bfs(grid,i,j);
                    if(newa!=0)area+=(newa);
                }
            }
        } 
        return area; 
    
}};