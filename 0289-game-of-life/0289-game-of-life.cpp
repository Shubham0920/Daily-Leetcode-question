class Solution {
public:
    void gameOfLife(vector<vector<int>>& board){
        int n = board.size(),  m = board[0].size();
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                for(int k=0; k<dir.size(); k++){
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(board[nx][ny] == 1 || board[nx][ny] == -2) count++;
                    }
                } 
                if(board[i][j] == 0){
                    if(count == 3) board[i][j] = -1;
                }
                else{
                    if(count < 2 || count > 3) board[i][j] = -2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == -1) board[i][j] = 1;
                if(board[i][j] == -2) board[i][j] = 0;
            }
        }

    }
};