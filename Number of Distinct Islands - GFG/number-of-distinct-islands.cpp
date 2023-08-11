//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>>& grid,vector<pair<int,int>> &vec,int row,int col){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        vec.push_back({i-row,j-col});
        int d[4][2]= {{-1,0},{0,-1},{1,0},{0,1}};
        
        for(int k=0;k<4;k++){
            int nrow = i+d[k][0];
            int ncol = j+d[k][1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(nrow,ncol,vis,grid,vec,row,col);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> se;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    se.insert(vec);
                }
            }
        }
        return se.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends