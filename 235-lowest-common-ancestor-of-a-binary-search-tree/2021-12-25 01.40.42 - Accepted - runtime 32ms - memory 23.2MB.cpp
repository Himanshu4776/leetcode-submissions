/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result is not found here go for other path
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            //result is not found here go for other path
            return left;
        }
        else { //if both left and right are not null, we have found the node from where both of our nodes path started means our result node.
            return root;
        }
    }
};