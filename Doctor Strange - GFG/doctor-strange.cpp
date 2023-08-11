//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int timer = 1;
    int cnt = 0;
    set<int> se;
    void dfs(int node,int parent,vector<int> &vis,int tin[],int low[],vector<int> adj[]){
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        int child = 0;
        for(auto x:adj[node]){
            if(x == parent) continue;
            if(!vis[x]){
                dfs(x,node,vis,tin,low,adj);
                low[node] = min(low[node],low[x]);
                if(low[x]>=tin[node] && parent !=-1){
                    se.insert(node);
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[x]);
            }
        }
        if(child>1 && parent == -1){
            se.insert(node);
        }
    }
    int doctorStrange(int N, int M, vector<vector<int>> & graph)
    {
         //Write your code here
         vector<int> vis(N+1,0);
         int low[N+1];
         int tin[N+1];
         
         vector<int> adj[N+1];
         for(int i=0;i<M;i++){
             adj[graph[i][0]].push_back(graph[i][1]);
             adj[graph[i][1]].push_back(graph[i][0]);
         }
         for(int i=0;i<N;i++){
             if(vis[i] == 0){
                 dfs(i,-1,vis,tin,low,adj);
             }
         }
         return se.size();
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}
// } Driver Code Ends