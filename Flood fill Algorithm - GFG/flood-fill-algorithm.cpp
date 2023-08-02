//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int k=image[sr][sc];
        image[sr][sc]=newColor;
        if(k == newColor)return image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int d[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()){
            
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int row=x+d[i][0];
                    int col=y+d[i][1];
                    if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && image[row][col]==k ){
                        image[row][col]=newColor;
                        q.push({row,col});
                    }
                }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends