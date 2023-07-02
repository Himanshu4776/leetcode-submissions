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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // bruteforce: store the traversal of p in array A and traversal of q in array B
        // Now atch if they ae equal or not.
        
        // optimized:
        if(p==NULL || q==NULL) return p==q;
        
        return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};