/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int postOrderSolver(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;

        int left = postOrderSolver(root->left, ans);
        int right = postOrderSolver(root->right, ans);

        ans = max(ans, left + right);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ans = 0;

        postOrderSolver(root, ans);

        return ans;
    }
};