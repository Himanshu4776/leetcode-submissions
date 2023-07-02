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
    int sum = 0;
    // check == true, then leaf is a left tree leaf
    // check == false, then leaf is a right tree leaf
    int solve(TreeNode* node, bool check)
    {
        if(node == NULL) return sum;
        
        solve(node->left, true);
        solve(node->right,false);
        
        if(node->left == NULL && node->right == NULL && check)
        {
            sum += node->val;
        }
        
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool check = false;
        solve(root,sum);
        return sum;
    }
};