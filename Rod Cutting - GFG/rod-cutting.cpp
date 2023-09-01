//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i,int price[],int n,vector<vector<int>> &dp){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n] != -1)return dp[i][n];
        
        int take = INT_MIN,nottake=INT_MIN;
        if((i+1)<=n){
            take = price[i] + solve(i,price,n-(i+1),dp);
        }
        nottake = solve(i-1,price,n,dp);
        return dp[i][n] = max(take,nottake);
        
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends