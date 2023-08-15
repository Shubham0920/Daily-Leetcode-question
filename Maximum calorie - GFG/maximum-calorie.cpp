//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int ind,int arr[],int n,vector<int> &dp){
	    if(ind>=n)return 0;
	    if(dp[ind] != -1) return dp[ind];
	    int one= INT_MIN,two=INT_MIN,nott = INT_MIN;
	    if(ind+1<n){
	        two = solve(ind+3,arr,n,dp) + arr[ind]+arr[ind+1];
	    }
	    one = solve(ind+2,arr,n,dp) + arr[ind];
	    nott = solve(ind+1,arr,n,dp);
	    return dp[ind] = max({one,two,nott});
	}
	int maxCalories(int arr[], int n)
	{
		
		// Your code goes here
		vector<int> dp(n+1,-1);
		return solve(0,arr,n,dp);

	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	    

	    Solution ob;
	    cout << ob.maxCalories(a, n) << "\n";

	     
    }
    return 0;
}
// } Driver Code Ends