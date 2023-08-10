//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


// } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &d, int duration[], int n, int m) {
        // 	Write your code here
        queue<int> q;
        vector<vector<int>> g(n);
        vector<int> indegree(n,0),dist(n,-1);
        for(int i=0;i<m;i++){
            g[d[i].first].push_back(d[i].second);
            indegree[d[i].second]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                dist[i] = duration[i];
                q.push(i);
            }
        }
        if(q.empty())return -1;
        // int ans = -1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto y:g[x]){
                dist[y] = max(dist[y],dist[x]+duration[y]);
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                }
            }
        }
        int ans =INT_MIN;
        for(auto x:dist){
            if(x == -1) return -1;
            ans = max(ans,x);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends