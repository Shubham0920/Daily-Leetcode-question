//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int i,int j,int n, int k, vector<vector<int>> &arr,vector<vector<vector<long long int>>> &dp){
        if(i==n-1 && j == n-1){
            return k==arr[i][j]?1:0;
        }
        if(k<0) return 0;
        if(i>=n || j>=n) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        return dp[i][j][k] = solve(i+1,j,n,k-arr[i][j],arr,dp) + solve(i,j+1,n,k-arr[i][j],arr,dp);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<long long int>>> dp(n+1,vector<vector<long long int>>(n+1,vector<long long int>(k+1,-1)));
        return solve(0,0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends