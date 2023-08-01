//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int dfs(int n,vector<int> &arr,vector<int> &vis,int ind){
        if(ind<0 || ind>=n)return 2;
        if(vis[ind] == 1) return vis[ind];
        vis[ind] = 1;
        return vis[ind] = dfs(n,arr,vis,ind+arr[ind]);
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                vis[i] = dfs(n,arr,vis,i+arr[i]);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 2){
                cnt++;
            }
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends