//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        // Your code goes here
        vector<vector<int>> vis(M,vector<int>(N,0));
        vector<vector<int>> dist(M,vector<int>(N,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j] == 'B'){
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        int d[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[x][y] = step;
            
            for(int i=0;i<4;i++){
                int nx = d[i][0]+x;
                int ny = d[i][1]+y;
                if(nx>=0&&ny>=0&&nx<M&&ny<N&&vis[nx][ny] == 0 && matrix[nx][ny] == 'O'){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},step+1});
                }
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(dist[i][j] == 0 && matrix[i][j] == 'O'){
                    dist[i][j] = -1;
                }
                else if(matrix[i][j] == 'W'){
                    dist[i][j] = -1;
                    
                }
            }
        }
        return dist;
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends