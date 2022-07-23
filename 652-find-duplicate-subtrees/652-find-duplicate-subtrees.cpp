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
    string solve(TreeNode* root,vector<TreeNode*> &ans,map<string,int> &st){
     // string s = "";
     if(root == nullptr){
         return "$";
     }
     
     string left = solve(root->left,ans,st);
     string right = solve(root->right,ans,st);
      string s =  to_string(root->val)+"left"+left+"right"+right;
     
     if(st[s] == 1){
         cout<<s<<endl;
         ans.push_back(root);
        //  return s;
     }
    st[s]++;
     return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
    map<string,int> st;
    solve(root,ans,st);
    return ans;
    }
};