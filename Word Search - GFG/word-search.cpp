//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int r,int c,vector<vector<int>> &vis,int ind,vector<vector<char>> &board,string s)
    {
        if(ind==s.length())
            return true;
        vis[r][c]=1;
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]==s[ind] && vis[nr][nc]==0)
            {
                if(solve(nr,nc,vis,ind+1,board,s))
                    return true;
            }
        }
        vis[r][c]=0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    if(solve(i,j,vis,1,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends