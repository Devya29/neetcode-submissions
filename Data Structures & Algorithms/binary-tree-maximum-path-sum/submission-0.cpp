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
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        // Handle negative contributions
        int leftSum=max(0,left);
        int rightSum=max(0,right);

        // Update global maximum using current node
        
        // if(leftSum>rightSum+root->val)return leftSum;
        // else if(rightSum>leftSum+root->val)return rightSum;
        // else if(leftSum+rightSum>root->val)
        ans = max(ans, root->val + leftSum + rightSum);
          // Return maximum single-branch sum
return root->val + max(leftSum, rightSum);
      
    }


    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};