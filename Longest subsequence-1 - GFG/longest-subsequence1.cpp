//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int last,int A[],int n,vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][last+1] != -1) return dp[i][last+1];
        int a = INT_MIN,b=INT_MIN;
        if(last == -1){
             a = solve(i+1,i,A,n,dp)+1;
             b = solve(i+1,last,A,n,dp);
        }
        if(abs(A[i]-A[last]) == 1){
             a = solve(i+1,i,A,n,dp)+1;
             b = solve(i+1,last,A,n,dp);
        }
        else{
             b = solve(i+1,last,A,n,dp);
        }
        return dp[i][last+1] = max(a,b);
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return solve(0,-1,A,N,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends