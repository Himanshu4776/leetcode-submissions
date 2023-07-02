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
    // long long int ans = 0; // Max Product answer
    // long long int inorder(TreeNode* root) {
    //     if(!root) return 0;

    //     return (inorder(root->left) + root->val + inorder(root->right));
    // }
    
    // int solve(TreeNode* root, int sum) {
    //     if(!root) return 0;

    //     long long l = solve(root->left,sum);
    //     long long r = solve(root->right,sum);
    //     long long upside = sum - l-r-root->val;
    //     // there can be 3 product options
    //     long long op1 = upside*(l+r+(long long)root->val);
    //     long long op2 = l*(upside+r+(long long)root->val);
    //     long long op3 = r*(l+upside+(long long)root->val);

    //     // check ans the max value to check with ans
    //     if(ans < max(op1,max(op2,op3))) {
    //         ans = max(op1,max(op2,op3));
    //     }
    //     // to return that subtree whole sum we will return l+r+root->val
    //     return (l+r+root->val);
    // }

    // int maxProduct(TreeNode* root) {
    //     // total sum of all the nodes
    //     long long int sum = inorder(root);
    //     // Now iterate the tree and check for the product value.
    //     solve(root,sum);
    //     return ans%1000000007;
    // }

    // More optimized approach:
    long long ans = 0, totalSum = 0;
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root); 
        dfs(root);
        return ans % int(1e9+7);
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
};