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
    int sum = INT_MIN;
    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            sum = max(sum,root->val);
            if(root->val<0){
                return 0;
            }
            return root->val;
        }
        int left = solve(root->left);
        int right =  solve(root->right);
        
        sum = max(sum,root->val+left+right);
        
        int x = root->val + max(left,right);
        
        if(x<0){
            return 0;
        }
        return x;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};