class Solution {
public:
    int cnt = 0;
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> leftrow,vector<int> &upperdiag,vector<int> lowerdiag,int n){
        if(col == n){
            cnt++;
            return ;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row] == 0 && lowerdiag[row+col] == 0 && upperdiag[n-1+row -col] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1; 
                lowerdiag[row+col] = 1; 
                upperdiag[n-1+row -col] = 1;
                solve(col+1,board,ans,leftrow,upperdiag,lowerdiag,n);
                board[row][col] = '.';
                leftrow[row] = 0; 
                lowerdiag[row+col] = 0; 
                upperdiag[n-1+row -col] = 0;
            }
        }
    }
    
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i] = s;
        
        vector<int> leftrow(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
        solve(0,board,ans,leftrow,upperdiag,lowerdiag,n);
        return cnt;
    }
};