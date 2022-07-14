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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while(!q.empty()){
            int n = q.size();
            map<int,vector<int>> m1;
            for(int i=0;i<n;i++){
                auto x = q.front();
                q.pop();

                int j= x.first;
                TreeNode* n = x.second;
                m1[j].push_back(n->val);
                // mp[i].push_back(n->val);
                if(n->left){
                    q.push({j-1,n->left});
                }

                if(n->right){
                    q.push({j+1,n->right});
                }
                }
            for(auto x:m1){
                sort(m1[x.first].begin(),m1[x.first].end());
                for(int i=0;i<m1[x.first].size();i++){
                mp[x.first].push_back(m1[x.first][i]);
            }
            }
        }
        vector<vector<int>> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};