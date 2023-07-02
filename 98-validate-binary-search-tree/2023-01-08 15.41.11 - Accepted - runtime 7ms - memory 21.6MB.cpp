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
    bool solve(TreeNode* root, TreeNode* low,TreeNode* high) {
        if(root == NULL) return true;
        if(low && root->val <= low->val || 
        high && root->val >= high->val) return false;
        
        // change the low and high and recurse now
        return (solve(root->left,low,root) &&
         solve(root->right,root,high));
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return solve(root,NULL, NULL );
    }
};