// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool iscycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &stack){
      if(vis[node] == 0){
          vis[node] = 1;
          stack[node] = 1;
          for(auto x:adj[node]){
              if(!vis[x] && iscycle(x,adj,vis,stack)){
                  return true;
              }
              else{
                  if(stack[x] == 1){
                      return true;
                  }
              }
          }
      }
      stack[node] = false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> stack(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i] && iscycle(i,adj,vis,stack)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends