//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int i,int arr[],int n,int last,vector<vector<int>> &dp){
	    if(i>=n){
	        return 0;
	    }
	    if(dp[i][last+1] != -1) return dp[i][last+1];
	    int take =INT_MIN,nottake=INT_MIN;
	    if(last == -1){
	        take = arr[i]+solve(i+1,arr,n,i,dp);
	        nottake = solve(i+1,arr,n,last,dp);
	       // cout<<take<<" "<<nottake<<endl;
	    }
	    else{
	        if(arr[i]>arr[last]){
	            take = arr[i]+solve(i+1,arr,n,i,dp);
	        }
	        nottake = solve(i+1,arr,n,last,dp);
	       //  cout<<take<<" "<<nottake<<endl;
	    }
	    return dp[i][last+1] = max(take,nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	    return solve(0,arr,n,-1,dp);
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends