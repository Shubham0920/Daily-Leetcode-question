//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	ll count(int i,int last,int n,vector<vector<int>> &dp){
	    if(i==n)return 1;
	    if(dp[i][last]!=-1)return dp[i][last];
	    if(last == 1){
	        return dp[i][last] = count(i+1,0,n,dp)%mod;
	    }
	    else{
	        return dp[i][last] = (count(i+1,0,n,dp)%mod+count(i+1,1,n,dp)%mod)%mod;
	    }
	}
	ll countStrings(int n) {
	    // code here
	    vector<vector<int>> dp(n+1,vector<int>(2,-1));
	    return count(0,0,n,dp)%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends