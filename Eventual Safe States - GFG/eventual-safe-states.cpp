//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> vis;
    map<int,int> m;
    bool dfs(int node,vector<int> adj[]){
        if(vis[node] == 1) return false;
        if(m[node]>0){
            vis[node] = 2;
            return true;
        }
        if(vis[node] == 2){
            return true;
        }
        vis[node] = 1;
        bool a = true;
        for(auto x:adj[node]){
            a = a&dfs(x,adj);
        }
        if(a){
            vis[node] = 2;
            return true;
        }
        else{
            return false;
        }
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        for(int i=0;i<V;i++){
            if(adj[i].size() == 0){
                m[i] = 1; 
            }
            else{
                m[i] = 0;
            }
        }
        vis = vector<int> (V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                dfs(i,adj);
            }
            if(vis[i] == 2){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends