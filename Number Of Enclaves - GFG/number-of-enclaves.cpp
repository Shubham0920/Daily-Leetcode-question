//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &b,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m||j>=n||b[i][j]!=1)return;
        b[i][j] = 0;
        dfs(b,i-1,j,m,n);
        dfs(b,i+1,j,m,n);
        dfs(b,i,j-1,m,n);
        dfs(b,i,j+1,m,n);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        vector<vector<int>> b = grid;
        int m = b.size();
        int n = b[0].size();
        for(int i=0;i<m;i++){
            if(b[i][0] == 1) dfs(b,i,0,m,n);
            if(b[i][n-1] == 1) dfs(b,i,n-1,m,n);
        }
        
        for(int i=0;i<n;i++){
            if(b[0][i] == 1) dfs(b,0,i,m,n);
            if(b[m-1][i] == 1) dfs(b,m-1,i,m,n);
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
        
        // vector<vector<int>> board = grid;
        // int m = board.size(), n=board[0].size();
        // if(m==0) return 0;
        // for(int i=0;i<m;i++){
        //     //left boundary
        //     if(board[i][0]==1) dfs(board, i, 0, m, n);
        //     //right boundary
        //     if(board[i][n-1]==1) dfs(board, i, n-1, m, n);
        // }

        // for(int i=0;i<n;i++){
        //     if(board[0][i]==1) dfs(board, 0, i, m, n);
        //     if(board[m-1][i]==1) dfs(board, m-1, i, m, n);
        // }
        // int cnt = 0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(board[i][j]==1){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        
    }
};
// void dfs(vector<vector<int>>& board, int x, int y, int m, int n){
//         if(x<0 || x>=m || y<0 || y>=n || board[x][y]!=1) return;
//         board[x][y]=0;
//         dfs(board, x+1, y, m, n);
//         dfs(board, x-1, y, m, n);
//         dfs(board, x, y+1, m, n);
//         dfs(board, x, y-1, m, n);
//     }




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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends