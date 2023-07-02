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
    int ans = 0;
    void f(TreeNode* root, int maxval) {
        if(root == NULL) return;
        
        if(root->val >= maxval) {
            ans++;
            maxval = root->val;
        }
        
        if(root->left) f(root->left, maxval);
        if(root->right) f(root->right, maxval);
    }
    int goodNodes(TreeNode* root) {
        f(root,root->val);
        return ans;
    }
};