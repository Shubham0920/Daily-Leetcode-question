class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> s;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0)
                    s.insert({i,j});
            }
        }
        for(auto x: s){
            int r = x.first;
            int c = x.second;
            
            for(int i=0;i<matrix[0].size();i++){
                matrix[r][i] = 0;
            }
           
            for(int i=0;i<matrix.size();i++){
                matrix[i][c] = 0;
            }
            
            s.erase(x);
        }
    }
};