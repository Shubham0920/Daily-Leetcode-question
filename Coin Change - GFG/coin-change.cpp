// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int knapsack(int s[],int n,int sum,vector<vector<long long int>> &dp){
        if(n == 0){
            return 0;
        }
        if(sum == 0){
            return dp[n][sum] = 1;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        if(s[n-1]<= sum){
            return dp[n][sum] = knapsack(s,n,sum-s[n -1],dp)+knapsack(s,n-1,sum,dp);
        }
        else{
            return dp[n][sum] = knapsack(s,n-1,sum,dp);
        }
    }
    long long int count(int s[], int m, int n) {

        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                if(j == 0){
                    dp[i][j] = 1;
                }
                if(i == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1] <= j){
                    dp[i][j] = dp[i][j-s[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends