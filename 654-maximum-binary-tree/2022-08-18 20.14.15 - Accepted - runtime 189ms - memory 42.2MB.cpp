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
    int maximum(vector<int>&nums,int l, int r) {
        int max_i = l;
        for(int i=l;i<r;i++) {
            if(nums[i] > nums[max_i]) max_i = i;
        }
        return max_i;
    }
    
    TreeNode* fill(vector<int>& nums, int l, int r) {
        if(l >=r) return NULL;
        
        int maxpos = maximum(nums,l,r);
        TreeNode* root = new TreeNode(nums[maxpos]);
        
        root->left = fill(nums, l, maxpos);
        root->right = fill(nums, maxpos+1, r);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return fill(nums, 0, nums.size());
    }
};