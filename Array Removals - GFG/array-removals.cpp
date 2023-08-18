//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int i,int j,vector<int> &arr,int k,vector<int> &dp){
        if(arr[j]-arr[i]<=k) return 0;
        if(i == arr.size() || j <0)return 0;
        
        if(dp[i] !=-1) return dp[i];
        int a = 1+solve(i+1,j,arr,k,dp);
        int b = 1+solve(i,j-1,arr,k,dp);
        int c = 2+solve(i+1,j-1,arr,k,dp);
        
        return dp[i] = min({a,b,c});
        
    }
    int removals(vector<int>& arr, int k){
        //Code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> dp(n+1,-1);
        return solve(0,n-1,arr,k,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends