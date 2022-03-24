// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
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
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(sum+1));
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	           if(i==0)
                dp[i][j]= 0;
           
               if(j==0)
               dp[i][j]= 1;
               
               if(i==0&&j==0)
               dp[i][j]=1;
	        }
	    }
	    
	    for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                   dp[i][j]= dp[i-1][j]||dp[i-1][j-arr[i-1]]; 
                }
                
                else if(arr[i-1]>j)
                
                {
                    dp[i][j]= dp[i-1][j];
                }
                
            }
	    }
	   int ans=0;
        int half=sum/2;
        for(int i=0;i<=half;i++)
            if(dp[n][i])
                ans=sum-2*i;
        return ans;
}
};


// { Driver Code Starts.
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends