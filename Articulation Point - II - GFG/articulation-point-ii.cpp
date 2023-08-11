//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int timer = 1;
  void dfs(int node,int parent,int tin[],int low[],vector<int> &vis,vector<int> &mark, vector<int>adj[]){
      vis[node] = 1;
      low[node] = tin[node] = timer;
      timer++;
      int child = 0;
      for(auto x:adj[node]){
          if(x == parent)continue;
          if(!vis[x]){
              dfs(x,node,tin,low,vis,mark,adj);
              low[node] = min(low[node],low[x]);
              if(low[x]>=tin[node] && parent != -1){
                  mark[node] = 1;
              }
              child++;
          }
          else{
              low[node] = min(low[node],tin[x]);
          }
      }
      if(child>1 && parent == -1){
          mark[node] = 1;
      }
  }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<int> mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,vis,mark,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0)return {-1};
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends