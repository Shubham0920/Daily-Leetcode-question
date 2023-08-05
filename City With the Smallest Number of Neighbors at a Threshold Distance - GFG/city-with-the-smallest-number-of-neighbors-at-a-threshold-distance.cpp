//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int shortest(int k,vector<vector<pair<int,int>>> g,int t,int n){
        
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
    
        dist[k] = 0;
        while(!q.empty()){
            int node = q.top().second;
            int weight = q.top().first;
            q.pop();
    
            for(auto x:g[node]){
                if(dist[x.first]>weight+x.second){
                    dist[x.first] = weight+x.second;
                    q.push({dist[x.first],x.first});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dist[i] <= t){
                cnt++;
            }
        }
        return cnt-1;
    }
    int findCity(int n, int m, vector<vector<int>>& edges,int t) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> ans(n,0);
        int a = INT_MAX;
        int p = -1;
        for(int i=0;i<n;i++){
            ans[i] = shortest(i,g,t,n);
            if(ans[i]<=a){
                a = ans[i];
                p = i;
            }
        }
        return p;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends