/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solver(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if (root == NULL) {
            return 0;
        }
        if(ans!=NULL)return 0;
        if (root->val == q->val || root->val == p->val) {
            int left = solver(root->left, p, q, ans);
            int right = solver(root->right, p, q, ans);
            if (left == 1 || right == 1) {
                ans = root;
                return 1;
            }else {
                return 1;
            }
        }
        int left = solver(root->left, p, q, ans);
        int right = solver(root->right, p, q, ans);
        if (left == 1 && right == 1) {
            ans = root;
            return 0;
        } else if (left == 1 || right == 1) {
            return 1;}
         else {
            return 0;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        solver(root,p,q,ans);
        return ans;
    }
};