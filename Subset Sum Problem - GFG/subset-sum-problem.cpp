// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool issubset(vector<int> arr,int sum,int n,vector<vector<int>> &dp){
        
        if(sum == 0){
            return dp[n][sum] = 1;
        }
        if(n == 0 || sum<0){
            return 0;
        }
        if(dp[n][sum] != -1){
           return dp[n][sum];
       }
       return dp[n][sum] = issubset(arr,sum-arr[n-1],n-1,dp) || issubset(arr,sum,n-1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // int dp[n+1][sum+1];
        vector<vector<int>> dp(arr.size()+1,vector<int> (sum+1,-1));
        // memset(dp,-1,sizeof(dp));
        return issubset(arr,sum,arr.size(),dp);
       
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends