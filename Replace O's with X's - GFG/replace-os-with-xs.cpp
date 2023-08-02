//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(vector<vector<char>>& board, int x, int y, int m, int n){
    if(x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') return;
    board[x][y]='#';
    dfs(board, x+1, y, m, n);
    dfs(board, x-1, y, m, n);
    dfs(board, x, y+1, m, n);
    dfs(board, x, y-1, m, n);
}
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n=board[0].size();
        if(m==0) return;
        for(int i=0;i<m;i++){
            //left boundary
            if(board[i][0]=='O') dfs(board, i, 0, m, n);
            //right boundary
            if(board[i][n-1]=='O') dfs(board, i, n-1, m, n);
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(board, 0, i, m, n);
            if(board[m-1][i]=='O') dfs(board, m-1, i, m, n);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        solve(mat);
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends