class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        vector<bool> vis(in.size(),0);
        
        for(int i=0;i<in.size();i++){
            if(vis[i] == 0){
                int start = in[i][0];
            int end = in[i][1];
            vis[i] = 1;
            for(int j=i+1;j<in.size();j++){
                if(in[j][0] <= end && vis[j] ==0){
                    end = max(in[j][1],end);
                    vis[j] = 1;
                }
            }
            ans.push_back({start,end});
            }
        }
        return ans;
    }
};