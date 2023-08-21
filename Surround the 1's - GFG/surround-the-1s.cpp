//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(int i,int j,vector<vector<int> >& mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()||mat[i][j] == 1){
            return 0;
        }
        return 1;
    }
    int Count(vector<vector<int> >& mat) {
        // Code here
        int cnt =0 ;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
               if(mat[i][j] == 1){
                    int zero=0;
                    zero += check(i+1,j,mat);
                    zero += check(i-1,j,mat);
                    zero += check(i,j-1,mat);
                    zero += check(i,j+1,mat);
                    zero += check(i+1,j+1,mat);
                    zero += check(i-1,j-1,mat);
                    zero += check(i+1,j-1,mat);
                    zero += check(i-1,j+1,mat);
                    if(zero%2==0 && zero != 0){
                        cnt++;
                    }
               }
            }
        }
        return cnt;
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends