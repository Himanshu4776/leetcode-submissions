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
    void solve(TreeNode* root, int path, int &ans) {
        if(root == NULL) return;
        
        // if we meet any value then we will toggle an upper bit by that value in 2^1.
        // n     n     n - 1  n & (n - 1)
            // --   ----   ----   -------
            //  0   0000   0111    0000
            //  1   0001   0000    0000
            //  2   0010   0001    0000
            //  3   0011   0010    0010
            //  4   0100   0011    0000
        
        path = path^(1 << root->val);
        if(root->left == NULL && root->right == NULL) {
            // here we will check no. of active bits
            if((path & (path-1)) == 0) ans++;
        }
        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};