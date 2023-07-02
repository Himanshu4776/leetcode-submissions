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
bool check(TreeNode* subRoot,TreeNode*root){
        
        if(root == NULL && subRoot != NULL)
            return false;
        
        if(root  && subRoot==NULL)
            return false;
        
        if(subRoot == NULL)
            return true;
        
        if(subRoot->val != root->val)
            return false;
        
        if(check(subRoot->left,root->left)==false)
            return false;
        
        if(check(subRoot->right,root->right)==false)
            return false;
        
        return true;
    
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL)
            return false;
        
        if(root->val==subRoot->val){
            
            if(check(subRoot,root))
                return true;
        
        }
        
        if(isSubtree(root->left,subRoot)==true)
            return true;
        
        if(isSubtree(root->right,subRoot)==true)
            return true;
        
        return false;
        
    }
};