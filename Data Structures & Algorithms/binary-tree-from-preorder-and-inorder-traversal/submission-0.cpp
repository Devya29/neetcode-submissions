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
    int index(vector<int>&inorder,int &num)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==num)return i;
        }
        return -1;
    }
    TreeNode* solver(vector<int>& preorder, vector<int>& inorder, int& preIndex, int start, int end)
    {
        if(start>end)return NULL;
        if(preIndex>preorder.size()-1)return NULL;
        // preorder se root element
        int element=preorder[preIndex];
        // inorder mein root ka index find karo
        int rootIndex=index(inorder,element);
        // root node banao
         TreeNode* root=new TreeNode(element);
        // preorder index increment karo
        preIndex++;
        // left subtree
        root->left=solver(preorder,inorder,preIndex,start,rootIndex-1);
        // right subtree
        root->right=solver(preorder,inorder,preIndex,rootIndex+1,end);
        // root return karo
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int preIndex = 0;
        return solver(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
};