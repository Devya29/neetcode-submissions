class Solution {
public:
    bool check(int i, int j, vector<vector<char>> &board,
	vector<vector<bool>> &vis,char c) {
		if (i < 0 || j < 0)
			return false;
		if (i < board.size() && j < board[0].size() &&
		board[i][j]==c && !vis[i][j])
		return true;
		return false;
	}
    bool solve(vector<vector<char>>& board, string &word,int i,int j,int k,vector<vector<bool>>&flag)
    {
        flag[i][j]=true;
        if(k>word.size()-1)return true;
        if(check(i+1,j,board,flag,word[k]))
        {
           bool a= solve(board,word,i+1,j,k+1,flag);
           if(a)return true;
        }
        if(check(i,j-1,board,flag,word[k]))
        {
            bool a= solve(board,word,i,j-1,k+1,flag);
           if(a)return true;
        }
        if(check(i,j+1,board,flag,word[k]))
        {
            bool a= solve(board,word,i,j+1,k+1,flag);
           if(a)return true;
        }
        if(check(i-1,j,board,flag,word[k]))
        {
            bool a= solve(board,word,i-1,j,k+1,flag);
           if(a)return true;
        }
        flag[i][j] = false;  
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int k,n=board.size(),m=board[0].size();
        vector<vector<bool>>flag(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                k=0;
                if(word[k]==board[i][j]){
                    flag[i][j]=true;
                    k++;
                    bool ans= solve(board,word,i,j,k,flag);
                    if(ans)return true;
                }
            }
        }
        return false;
    }
};