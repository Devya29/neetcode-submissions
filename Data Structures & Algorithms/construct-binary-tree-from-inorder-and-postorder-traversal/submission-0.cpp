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
    int findIndex(unordered_map<int,int>&tracker,int &ele)
    {
        return tracker[ele];
    }
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder,int &postIndex,int start,int end,unordered_map<int,int>&tracker)
    {
        if(postIndex<0)return NULL;
        if(start>end)return NULL;

        int element=postorder[postIndex];
        postIndex--;
        TreeNode* root=new TreeNode(element);
        int rootIndex=findIndex(tracker,element);
        root->right=solver(inorder,postorder,postIndex,rootIndex+1,end,tracker);
        root->left=solver(inorder,postorder,postIndex,start,rootIndex-1,tracker);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>tracker;
        for(int i=0;i<inorder.size();i++)
        {
            tracker[inorder[i]]=i;
        }
        int postIndex=postorder.size()-1;
        return solver(inorder,postorder,postIndex,0,postorder.size()-1,tracker);
    }
};