//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int dfs(int a,int b,int &mini,vector<vector<pair<int,int>>> g){
        if(g[a].size() == 0){
            mini =  min(mini,b);
            return a;
        }
        if(mini>b){
            mini = b;
        }
        return dfs(g[a][0].first,g[a][0].second,mini,g);
        
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<vector<pair<int,int>>> g(n+1);
        vector<vector<int>> ans;
        vector<int> indegree(n+1);
        for(int i=0;i<p;i++){
            g[a[i]].push_back({b[i],d[i]});
            indegree[b[i]]++;
        }
        for(int i=0;i<n+1;i++){
            if(i !=0 && indegree[i] == 0 && g[i].size()>0){
                int mini = INT_MAX;
                int num = dfs(g[i][0].first,g[i][0].second,mini,g);
                ans.push_back({i,num,mini});
                
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends