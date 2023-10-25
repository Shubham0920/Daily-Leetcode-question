//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int dp[1002][1002];
    int knapSack1(int W, int wt[], int val[], int n) 
    { 
       if(n == 0 || W == 0){
           return 0;
       }
       if(dp[n][W] != -1){
           return dp[n][W];
       }
       if(wt[n-1]<=W){
           return dp[n][W] = max(val[n-1]+knapSack1( W-wt[n-1],  wt,  val,  n),knapSack1( W,  wt,  val,  n-1));
       }
       else{
           return dp[n][W] = knapSack1( W,  wt,  val,  n-1);
       }
    }
    
   
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
       return knapSack1( W,  wt,  val,  n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends