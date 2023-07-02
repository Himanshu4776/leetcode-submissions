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
    void inorder(TreeNode* node, vector<int>&val)
    {
        if(node == NULL) return;
        if(node->left) inorder(node->left,val);
        val.push_back(node->val);
        if(node->right) inorder(node->right,val);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>val;
        inorder(root,val);
        return val;
    }
};