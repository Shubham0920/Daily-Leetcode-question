//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i<0 && j<0) return 1;
        if(j<0) return 1;
        if(i<0 && j>=0) return 0;
        // if(j<0) return 1;
        // if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }
    int countWays(string s, string t){
        // code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends