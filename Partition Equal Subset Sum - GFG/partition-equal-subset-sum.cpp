//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool issubset(int arr[],int sum,int n,vector<vector<int>> &dp){
        
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
    
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2 != 0){
            return 0;
        }
        else{
            sum /=2;
            vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
            bool ans = issubset(arr,sum,n,dp);
            if(ans)
            {return 1;}
            else{
                return 0;
            }
        }
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends