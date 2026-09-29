/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrderSolver(TreeNode* root,int depth,int &ans)
    {   
        if(root==NULL)return ;
        depth++;
        ans=max(depth,ans);
        preOrderSolver(root->left,depth,ans);
        preOrderSolver(root->right,depth,ans);
    }
    int postOrderSolver(TreeNode* root)
    {
        if(root==NULL)return 0;
        int left=1+postOrderSolver(root->left);
        int right=1+postOrderSolver(root->right);
        return max(left,right);

    }
    // int maxDepth(TreeNode* root) {
    //     int ans=0;
    //     int depth=0;
    //     if(root==NULL)return 0;
    //     preOrderSolver(root,depth,ans);
    //     return ans;
    // }
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)return 0;
        int leftans=postOrderSolver(root->left);
        int rightans=postOrderSolver(root->right);
        return max(leftans,rightans)+1;
    }
};