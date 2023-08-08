//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int cnt = 1;
    void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &low,vector<int> &in,
            set<vector<int>> &bridges){
                
                vis[node] = 1;
                low[node] = cnt;
                in[node] = cnt;
                cnt++;
                
                for(auto it:adj[node]){
                    if(it == parent) continue;
                    if(!vis[it]){
                        dfs(it,node,adj,vis,low,in,bridges);
                        low[node] = min(low[node],low[it]);
                        if(low[it]>in[node]){
                            bridges.insert({it,node});
                        }
                    }
                    else{
                        low[node] = min(low[node],low[it]);
                    }
                }
                
        }
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(n,0);
        vector<int> low(n,0),in(n,0);
        
        set<vector<int>> bridges;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,low,in,bridges);
            }
        }
        if(bridges.find({c,d}) != bridges.end() || bridges.find({d,c}) != bridges.end()){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends