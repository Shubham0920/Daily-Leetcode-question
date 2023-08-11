//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int> ans;
    void precompute(){
        vector<bool> isprime(1000001,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i<=1000000;i++){
            if(isprime[i]){
                ans.push_back(i);
                for(int j=2*i;j<=1000000;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }
    void DFS(vector<int> adj[],int u,vector<int>& visited,int& count){
        visited[u] = true;
        
        count++;
        
        for(auto& v: adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,count);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<int> adj[n+1];           //Using Unordered_map<int,vector<int>> adj will give TIME LIMIT EXCEED
        
        for(auto vec: g){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(n+1,0);
        int maxi = INT_MIN;
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                int count = 0;
                DFS(adj,i,visited,count);
                maxi = max(maxi,count);
            }
        }
        if(maxi == 1){
            return -1;
        }
        return ans[maxi-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g;
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g.push_back({u, v});
// 			g[u].push_back(v);
// 			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends