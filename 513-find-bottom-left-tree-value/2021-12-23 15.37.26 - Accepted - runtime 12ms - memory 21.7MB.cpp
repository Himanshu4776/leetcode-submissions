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
    void f(TreeNode* node, int depth,int &maxdepth,int &ans){
        if(node == NULL) return;
        
        f(node->left,depth+1,maxdepth,ans);
        f(node->right,depth+1,maxdepth,ans);
        
        if(depth > maxdepth)
        {
            maxdepth = depth;
            ans = node->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val,depth=0,maxdepth=0;
        f(root,depth,maxdepth,ans);
        return ans;
    }
};