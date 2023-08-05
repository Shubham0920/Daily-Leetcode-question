//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> matrix)
    {
        //code here
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> vis(M,vector<int>(N,0));
        // vector<vector<int>> dist(M,vector<int>(N,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        int d[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        int ans = -1;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans = step;
            
            for(int i=0;i<4;i++){
                int nx = d[i][0]+x;
                int ny = d[i][1]+y;
                if(nx>=0&&ny>=0&&nx<M&&ny<N&&vis[nx][ny] == 0 && matrix[nx][ny] == 1){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},step+1});
                }
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(vis[i][j] == 0 && matrix[i][j] == 1){
                    return -1;
                }
                
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends