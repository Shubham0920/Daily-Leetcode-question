//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int cnt = 0;
    bool solve(int node,int pl,vector<vector<int>> &g,vector<int> &vis){
       vis[node] = 1;
       bool select = false;
       
       for(auto x:g[node]){
           if(vis[x] == 0 && !solve(x,pl,g,vis)){
               select = true;
           }
       }
       if(select){
           cnt++;
       }
       return select;
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<vector<int>> g(N+1);
        for(int i=0;i<N-1;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(N+1,0);
        solve(1,0,g,vis);
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends