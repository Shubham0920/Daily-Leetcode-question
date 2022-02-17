class Solution {
public:
    bool issafe(vector<vector<char>>& grid,int row,int col,vector<vector<bool>>& vis,int ROW,int COL){
        if(row >=0 && row<ROW){
            if(col>=0 && col<COL){
                if(grid[row][col] == '1' && !vis[row][col]){
                    return true;
                }
            }
        }
        return false;
    }
    void DFS(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis,int ROW,int COL){
        vis[i][j] = 1;
        // if(issafe(grid,i-1,j-1,vis,ROW,COL))    DFS(grid,i-1,j-1,vis,ROW,COL);
        if(issafe(grid,i-1,j,vis,ROW,COL))    DFS(grid,i-1,j,vis,ROW,COL);
        // if(issafe(grid,i-1,j+1,vis,ROW,COL))    DFS(grid,i-1,j+1,vis,ROW,COL);
        if(issafe(grid,i,j-1,vis,ROW,COL))    DFS(grid,i,j-1,vis,ROW,COL);
        if(issafe(grid,i,j+1,vis,ROW,COL))    DFS(grid,i,j+1,vis,ROW,COL);
        if(issafe(grid,i+1,j,vis,ROW,COL))    DFS(grid,i+1,j,vis,ROW,COL);
        // if(issafe(grid,i+1,j+1,vis,ROW,COL))    DFS(grid,i+1,j+1,vis,ROW,COL);
        // if(issafe(grid,i+1,j-1,vis,ROW,COL))    DFS(grid,i+1,j-1,vis,ROW,COL);
            
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(row,vector<bool>(col,0));
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[i].size();j++){
                    if(grid[i][j] == '1' && !vis[i][j]){
                        DFS(grid,i,j,vis,row,col);
                        count++;
                    }
                }
            }
        return count;
    }
};