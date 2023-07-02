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
    // set<int> s;
    // void traverse(TreeNode* root){
    //     if(!root) return;
    //     s.insert(root->val);
    //     traverse(root->left);
    //     traverse(root->right);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     traverse(root);
    //     for(int val:s){
    //         k--;
    //         if(k == 0) return val;
    //     }
    //     return 0;
    // }
    int count = 0;
    int res = -1;
    void helper( TreeNode* root, int k){
        if( root != NULL){
            if( res != -1) return;
            helper( root->left,k);
            count++;
            if( count == k){
                res = root->val;
                return;
            }
            
            helper(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        
        helper(root,k);
        return res;
    }
};