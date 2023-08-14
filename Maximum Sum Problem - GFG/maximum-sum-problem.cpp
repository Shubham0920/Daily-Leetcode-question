//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int solve(int n,vector<int> &dp){
             if(n<=1){
                return n;
            }
            if(dp[n] != -1){
                return dp[n];
            }
            int sum = 0;
            sum+=solve(n/2,dp);
            sum+=solve(n/3,dp);
            sum+=solve(n/4,dp);
            return dp[n] = max(sum,n);
        }
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1,-1);
            dp[0] = 0;
            for(int i=1;i<=n;i++){
                 int sum = 0;
                sum+=solve(n/2,dp);
                sum+=solve(n/3,dp);
                sum+=solve(n/4,dp);
                dp[n] = max(sum,i);
            }
            return dp[n];
           
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends