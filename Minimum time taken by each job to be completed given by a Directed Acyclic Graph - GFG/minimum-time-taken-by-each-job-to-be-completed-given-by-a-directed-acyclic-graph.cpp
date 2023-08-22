//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int me)
        {
            // code here  
            vector<vector<int>> g(n+1);
            vector<int> indegree(n+1,0);
            map<int,int> m;
            for(int i=0;i<me;i++){
                int a = edges[i][0];
                int b = edges[i][1];
                g[a].push_back(b);
                indegree[b]++;
            }
            queue<int> q;
            for(int i=1;i<=n;i++){
                if(indegree[i] == 0)q.push(i);
            }
            int time = 0;
            while(!q.empty()){
                time++;
                int size = q.size();
                for(int i=0;i<size;i++){
                    int x = q.front();
                    q.pop();
                    // cout<<x<<time<<endl;
                    m[x] = time;
                    for(auto it:g[x]){
                        indegree[it]--;
                        if(indegree[it] == 0){
                            q.push(it);
                        }
                    }
                }
            }
            vector<int> ans(n);
            for(int i=1;i<=n;i++){
                ans[i-1] = m[i];
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends