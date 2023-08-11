//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    string exercise(int n, int M, vector<vector<int>> A, int src, int dest, int X){
        // code here
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0;i<A.size();i++){
            g[A[i][0]].push_back({A[i][1],A[i][2]});
            g[A[i][1]].push_back({A[i][0],A[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,src});
        vector<long long> dist(n+1,INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()){
            long long node = q.top().second;
            long long w = q.top().first;
            q.pop();
            for(auto x:g[node]){
                if(dist[x.first]>w+x.second){
                    dist[x.first]=w+x.second;
                    q.push({dist[x.first],x.first});
                }
            }
        }
        // cout<<dist[dest]<<endl;
        if(dist[dest]>X){
            return "Neeman's Wool Joggers";
        }
        
        return "Neeman's Cotton Classics";
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M, src, dest, X;
        cin >> N >> M >> src >> dest >> X;
        vector<vector<int>> A(M, vector<int> (3, 0));
        for(int i = 0; i < M; i++){
            cin >> A[i][0] >> A[i][1] >> A[i][2];
        }
        Solution obj;
        cout << obj.exercise(N, M, A, src, dest, X) << "\n";
    }
}

// } Driver Code Ends