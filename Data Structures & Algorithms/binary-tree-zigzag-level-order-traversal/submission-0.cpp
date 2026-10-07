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
void reverseQueue(queue<TreeNode*>& q) {
    stack<TreeNode*> s;
    // Move all elements from queue to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    // Move all elements from stack back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        ans.push_back({root->val});
        queue<TreeNode*> q;
        q.push(root);
        int swich=1;
        while(!q.empty())
        {
            vector<int>temp;
            int n=q.size();
            if(swich==0)
            {
                for(int i=0;i<n;i++)
                {
                    TreeNode* front=q.front();
                    q.pop();
                    if(front->left!=NULL)
                    {
                        q.push(front->left);
                        temp.push_back(front->left->val);
                    }
                    if(front->right!=NULL)
                    {
                        q.push(front->right);
                        temp.push_back(front->right->val);
                    }
                }
                swich=1;
                reverseQueue(q);
                if(!temp.empty())
                ans.push_back(temp);
            }else{
                 for(int i=0;i<n;i++)
                {
                    TreeNode* front=q.front();
                    q.pop();
                    if(front->right!=NULL)
                    {
                        q.push(front->right);
                        temp.push_back(front->right->val);
                    }
                    if(front->left!=NULL)
                    {
                        q.push(front->left);
                        temp.push_back(front->left->val);
                    }
                }
                swich=0;
                reverseQueue(q);
                if(!temp.empty())
                ans.push_back(temp);
            }
        }
        return ans;
    }
};