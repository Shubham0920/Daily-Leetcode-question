//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<long> dist(n,LONG_MAX);
        vector<long> ways(n,0);
        int mod = (int)(1e9 + 7);
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> q;
        q.push({0,0});
        
        int cnt = 1;
        dist[0] = 0;
        ways[0] = 1;
        while(!q.empty()){
            int node = q.top().second;
            long weight = q.top().first;
            q.pop();
    
            for(auto x:g[node]){
                if(dist[x.first]>weight+x.second){
                    dist[x.first] = weight+x.second;
                    ways[x.first] = ways[node]%mod;
                    q.push({dist[x.first],x.first});
                }
                else if(dist[x.first] == weight+x.second){
                    ways[x.first] = (ways[x.first] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]% mod;
    }
    
    // vector<vector<vector<int>>>adjL(n);
        
    //     for(int i=0;i<roads.size();i++)
    //     {
    //         adjL[roads[i][0]].push_back({roads[i][1],roads[i][2]});
    //         adjL[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    //     }
    //     vector<long>dist(n,LONG_MAX);
    //     int MOD = 1000000007;
    //     vector<long>ways(n,0);
    //     ways[0] = 1;
    //     priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>>pQ;
    //     pQ.push({0,0});
    //     dist[0] = 0;
    //     long cost;
    //     int node; 
    //     while(!pQ.empty())
    //     {
    //         cost = pQ.top().first;
    //         node = pQ.top().second;
    //         pQ.pop();
            
    //         if(dist[node]<cost)continue;
            
    //         for(auto &adj: adjL[node])
    //         {                
    //             if(dist[node]+adj[1] < dist[adj[0]])
    //             {
    //                 dist[adj[0]] = dist[node]+adj[1];
    //                 ways[adj[0]] = ways[node];
    //                 pQ.push({dist[adj[0]],adj[0]});
    //             }
            
    //             else if(dist[node]+adj[1] == dist[adj[0]])
    //             {
    //                 ways[adj[0]] = (ways[adj[0]] + ways[node])%MOD;
    //             }
    //         }
    //     }
    //     return ways[n-1];
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends