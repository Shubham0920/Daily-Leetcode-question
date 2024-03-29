//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	bool solve(int r,int c,vector<vector<int>> &vis,int ind,vector<vector<char>> &board,string s)
    {
        if(ind==s.length())
            return true;
        vis[r][c]=1;
        int dr[]={1,0,-1,0,1,-1,1,-1};
        int dc[]={0,1,0,-1,1,1,-1,-1};
        for(int i=0;i<8;i++)
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
 
vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
    
    int n=board.size();
    int m=board[0].size();
    vector<string> ans;
    set<string> st;
    for(auto it:dictionary)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        string s=it;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==s[0])
                {
                    if(solve(i,j,vis,1,board,s))
                    {   if(st.find(s)==st.end())
                        {
                            ans.push_back(s);
                            st.insert(s);
                        }
                        
                    }
                }
            }
        }
    }
    return ans;
    // Code here
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends