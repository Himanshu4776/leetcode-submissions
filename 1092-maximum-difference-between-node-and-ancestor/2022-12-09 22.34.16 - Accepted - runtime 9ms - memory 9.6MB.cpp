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
    int solve(TreeNode* root, int minval, int maxval) {
        if(!root) return (maxval-minval);

        maxval = max(maxval,root->val);
        minval = min(minval,root->val);

        int left = solve(root->left, minval, maxval);
        int right = solve(root->right, minval, maxval);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;

        return solve(root,root->val,root->val);
    }
};