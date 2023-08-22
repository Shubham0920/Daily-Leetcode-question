//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int solve(int i,vector<int> &a,vector<int> &dp){
      if(i>=a.size()){
          return 0;
      }
      if(dp[i] != -1) return dp[i];
      int A = INT_MIN,B=INT_MIN,C=INT_MIN;
      A = a[i] + solve(i+2,a,dp);
      B = solve(i+1,a,dp);
      
      if(i+1<a.size()){
          C = a[i]+a[i+1]+solve(i+3,a,dp);
      }
      return dp[i] = max({A,B,C});
  }
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size()-1;
      vector<int> dp(n+1,-1);
      return solve(0,a,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends