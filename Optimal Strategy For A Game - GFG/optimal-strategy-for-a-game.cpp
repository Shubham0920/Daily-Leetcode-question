//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int i,int j,int a[],vector<vector<long long>> &dp){
        if(i == j){
            return a[i];
        }
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a1 = a[i] + min(solve(i+2,j,a,dp),solve(i+1,j-1,a,dp));
        int a2 = a[j] + min(solve(i+1,j-1,a,dp),solve(i,j-2,a,dp));
        return dp[i][j] = max(a1,a2);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
	    return solve(0,n-1,arr,dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends