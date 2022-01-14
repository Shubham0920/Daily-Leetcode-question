class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] != '.'){
                    char temp=board[i][j];
                    board[i][j]='+';
                    if(!isvalid(board,i,j,temp)){
                        return false;
                    }
                    board[i][j]=temp;
                    
                }
            }
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>>& v,int r,int col,char c){
        for(int i=0;i<9;i++){
            if(v[i][col]==c){
                return false;
            }
            if(v[r][i]==c)return false;
            if(v[3*(r/3)+i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool x = solve(board);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return x;
    }
};