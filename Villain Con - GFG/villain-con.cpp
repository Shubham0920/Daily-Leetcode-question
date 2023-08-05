//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<vector<int>> g(N+1);
        vector<int> indegree(N+1,0);
        for(int i=0;i<M;i++){
            g[mat[i][0]].push_back(mat[i][1]);
            indegree[mat[i][1]]++;
        }
        queue<int> q;
        int level=0;
        for(int i=1;i<=N;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();
                for(auto x:g[top]){
                    indegree[x]--;
                    if(indegree[x] == 0){
                        q.push(x);
                    }
                }
            }
            level++;
        }
        return level;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends