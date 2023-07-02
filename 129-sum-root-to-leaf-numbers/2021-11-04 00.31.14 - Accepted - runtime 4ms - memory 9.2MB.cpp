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
    int preorder(TreeNode*root,int value)
    {
        if(!root) return 0;
        value = root->val + value*10;
        // int res = 0;
        if(root->left == NULL && root->right == NULL)
        {
            return value;
        }
        return preorder(root->left,value) + preorder(root->right,value);
    }
    int sumNumbers(TreeNode* root) {
        return preorder(root,0);
    }
};