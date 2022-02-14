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
    int sum = 0;
    void findnum(TreeNode* root,int v){
        if(root == NULL){
            return;
        }
        if(root->left)findnum(root->left,v*10+root->val);
        if (root->right)findnum(root->right,v*10+root->val);
        if(!root->left && !root->right){
            sum += v*10+root->val;
        }
    }
    int sumNumbers(TreeNode* root) {
        findnum(root,0);
        return sum;
    }
};