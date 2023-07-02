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
    int dfsHeight(TreeNode* root)
    {
        if(root == NULL)
            return true;
        
        int lth = dfsHeight(root->left);
        int rth = dfsHeight(root->right);
        if(lth == -1 || rth == -1 || abs(lth - rth) > 1){
            return -1;
        }
        return 1+max(lth,rth);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        return dfsHeight(root) != -1;
    }
};