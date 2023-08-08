//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> parent,rank;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findpar(int a){
	    if(a==parent[a]){
	        return a;
	    }
	    return parent[a] = findpar(parent[a]);
	}
	void union_(int a,int b){
	    int para = findpar(a);
	    int parb = findpar(b);
	    if(para==parb) return ;
	    if(rank[para]<rank[parb]){
	        parent[para] = parb;
	    }
	    else if(rank[para]>rank[parb]){
	        parent[parb] = para;
	    }
	    else{
	        parent[para] = parb;
	        rank[parb]++;
	    }
	}
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        
        vector<pair<int,pair<int,int>>> vec;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j][0];
                int wt = adj[i][j][1];
                int u=i;
                vec.push_back({wt, {u, v}});
            }
        }
        sort(vec.begin(),vec.end());
        int mst = 0;
        for(int i=0;i<vec.size();i++){
            int w = vec[i].first;
            int a = vec[i].second.first;
            int b = vec[i].second.second;
            if(findpar(a)!=findpar(b)){
                union_(a,b);
                mst += w;
            }
        }
        return mst;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends