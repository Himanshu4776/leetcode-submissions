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
private:
    int findpath(TreeNode* node,int &maxi) {
        if(node==NULL) return 0;
        
        int leftsum = max(0,findpath(node->left,maxi));
        int rightsum = max(0,findpath(node->right,maxi));
        // maxi = max(maxi,node->val);
        // this will give max value node val.
        maxi = max(maxi,(node->val + leftsum + rightsum));
        
        return node->val + max(leftsum,rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        findpath(root,maxi);
        return maxi;
    }
};