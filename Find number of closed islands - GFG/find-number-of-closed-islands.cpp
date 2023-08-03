//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>>& board, int x, int y, int m, int n){
        if(x<0 || x>=m || y<0 || y>=n || board[x][y]!=1) return;
        board[x][y]=0;
        dfs(board, x+1, y, m, n);
        dfs(board, x-1, y, m, n);
        dfs(board, x, y+1, m, n);
        dfs(board, x, y-1, m, n);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>> board = matrix;
        int m = board.size(), n=board[0].size();
        if(m==0) return 0;
        for(int i=0;i<m;i++){
            //left boundary
            if(board[i][0]==1) dfs(board, i, 0, m, n);
            //right boundary
            if(board[i][n-1]==1) dfs(board, i, n-1, m, n);
        }

        for(int i=0;i<n;i++){
            if(board[0][i]==1) dfs(board, 0, i, m, n);
            if(board[m-1][i]==1) dfs(board, m-1, i, m, n);
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    dfs(board,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends