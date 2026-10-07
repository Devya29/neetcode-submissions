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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        ans.push_back({root->val});
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();  
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* front = q.front();
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                    temp.push_back(front->left->val);
                }
                if(front->right!=NULL)
                {
                    q.push(front->right);
                    temp.push_back(front->right->val);
                }
            }
            if(!temp.empty())
            ans.push_back(temp);
        }
        return ans;
    }
};