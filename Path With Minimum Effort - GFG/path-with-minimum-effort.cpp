//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
       q.push({0,{0,0}});
       dist[0][0] = 0;

       int d[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

       while(!q.empty()){
           int diff = q.top().first;
           int row = q.top().second.first;
           int col = q.top().second.second;
           q.pop();
           if(row == m-1 && col == n-1){
               return diff;
           }
           for(int i=0;i<4;i++){
               int nrow = d[i][0] + row;
               int ncol = d[i][1] + col;

               if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                   int newdiff = max(diff,abs(grid[row][col]-grid[nrow][ncol]));
                   if(newdiff<dist[nrow][ncol]){
                       dist[nrow][ncol] = newdiff;
                       q.push({dist[nrow][ncol],{nrow,ncol}});
                   }
               }
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends