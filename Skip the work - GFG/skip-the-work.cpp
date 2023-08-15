//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

#include<vector>
class Solution
{
  public:
    int f(int i,int flag,int nums[],vector<vector<int>> &dp){
        // cout<<ind<<skip<<endl;
        if(i < 0) return 0;
        // int ans = INT_MAX;
        if(dp[i][flag] != -1) return dp[i][flag];
      // int take , notTake = INT_MAX;
        
        if(flag){
             dp[i][flag]=min(f(i-1,1,nums , dp)+nums[i],f(i-1,0,nums , dp));
        }else{
                dp[i][flag]=f(i-1,1,nums , dp)+nums[i];
        }
        return dp[i][flag];
        }
    int minAmount(int nums[] , int n)
    {
        //code here.
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        for(int i = n-1; i>=0; i--){
            for(int flag = 0; flag<= 1; flag++){
              if(flag){
             dp[i][flag]=min(dp[i+1][1]+nums[i],dp[i+1][0]);
        }else{
                dp[i][flag]=dp[i+1][1]+nums[i];
        }
        
            }
        }
        return dp[0][1];
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
            int arr[n];
            for(int i = 0;i<n;i++)
                cin>>arr[i];
            Solution ob;    
            cout<<ob.minAmount(arr,n)<<endl;    
        }
}
// } Driver Code Ends