class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            cout<<"====";
                            board[i][j] = c;
                            if(solve(board) == true){
                                return true;
                            }
                            else
                                board[i][j] = '.';
                            
                        }
                    }
                    return false;
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
    
    void solveSudoku(vector<vector<char>>& board) {
        bool x = solve(board);
    }
};


// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& v) {
//         solve(v);
//     }
//     bool solve(vector<vector<char>>& v){
//         for(int i=0;i<v.size();i++){
//             for(int j=0;j<v[0].size();j++){
            //    if(v[i][j]=='.'){
            //        for(char c='1';c<='9';c++){ 
            //            if(isValid(v,i,j,c)){
            //                 v[i][j]=c;
            //                if(solve(v)){
            //                    return true;
            //                }else{
            //                    v[i][j]='.';
            //                }  
            //            }
            //        }
            //        return false;
            //    }         
            // }
            
//         }
//         return true;
//     }
//     bool isValid(vector<vector<char>>& v,int r,int col,char c){
//         for(int i=0;i<9;i++){
//             if(v[i][col]==c){
//                 return false;
//             }
//             if(v[r][i]==c)return false;
//             if(v[3*(r/3)+i/3][3*(col/3)+i%3]==c)return false;
//         }
//         return true;
//     }
    
// };