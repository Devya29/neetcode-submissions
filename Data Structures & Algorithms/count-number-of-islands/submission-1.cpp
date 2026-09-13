class Solution {
public:
    bool exploreable(vector<vector<char>>&grid,int i,int j){
        if(i<0||j<0)return false;
        if(i<grid.size()&&j<grid[0].size()&&grid[i][j]=='1')return true;
        return false;
    }
   void dfs(vector<vector<char>>&grid,int i,int j)
    {
        grid[i][j]='0';
        //UP
        if(exploreable(grid,i-1,j)){
            dfs(grid, i-1, j);
        }
        //RIGHT
        if(exploreable(grid,i,j+1)){
            dfs(grid, i, j+1);
        }
        //LEFT
        if(exploreable(grid,i,j-1)){
            dfs(grid, i, j-1);
        }
        //DOWN
        if(exploreable(grid,i+1,j)){
            dfs(grid, i+1, j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count ;
    }
};