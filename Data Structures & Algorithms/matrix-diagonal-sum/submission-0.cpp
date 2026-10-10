class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
     int k=0,leftSum=0,rightSum=0;
     for(int i=0;i<mat.size();i++)
     {
        leftSum+=mat[i][k];
        k++;
     }   
    k--;
    for(int i=0;i<mat.size();i++)
    {
        if(i==k)
        {
            k--;continue;}
        rightSum+=mat[i][k];
        k--;
        
    }
    return leftSum+rightSum;
    }
};