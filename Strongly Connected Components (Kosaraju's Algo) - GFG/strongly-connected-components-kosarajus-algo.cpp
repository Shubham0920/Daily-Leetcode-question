//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node , vector<vector<int>>& adj,vector<int> &vis,stack<int> &st){
	    vis[node] = 1;
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs(x,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node , vector<vector<int>>& adjT,vector<int> &vis){
	    vis[node] = 1;
	    for(auto x:adjT[node]){
	        if(!vis[x]){
	            dfs2(x,adjT,vis);
	        }
	    }

	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<vector<int>> adjT(V);
        
        for(int i=0;i<V;i++){
            for(auto it :adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc = 0 ;
        vector<int> vis1(V,0);
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            if(vis1[x] == 0){
                dfs2(x,adjT,vis1);
                scc++;
            }
        }
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends