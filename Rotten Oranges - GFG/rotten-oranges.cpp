//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int one = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    one++;
                }        
            }
        }
        if(one == 0)return 0;
        int d[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        int ans = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                pair<int,int> top = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = d[i][0];
                    int y = d[i][1];
                    x+=top.first;
                    y+=top.second;
                    if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y] = 2;
                        one--;
                    }
                }
            }
            ans++;
        }
        if(one !=0)return -1;
        return ans-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends