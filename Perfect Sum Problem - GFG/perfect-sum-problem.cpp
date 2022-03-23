// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007 
	int perfectsum(int arr[],int n,int sum,vector<vector<int>> &dp){
	    if(n == 0 && sum == 0){
	        return dp[n][sum] = 1;
	    }
	    if(n==0 || sum<0){
	        return 0;
	    }
	    
	    if(dp[n][sum] != -1){
	        return dp[n][sum]%mod;
	    }
	    
	    return dp[n][sum] = (perfectsum(arr,n-1,sum-arr[n-1],dp)%mod + perfectsum(arr,n-1,sum,dp)%mod)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return perfectsum(arr,n,sum,dp);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends