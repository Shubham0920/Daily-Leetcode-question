//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int mod = 1e9+7;
	int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = (solve(i-1,j-1,s,t,dp)%mod + solve(i-1,j,s,t,dp)%mod)%mod;
        }
        return dp[i][j] = solve(i-1,j,s,t,dp)%mod;
    }
    int TotalWays(string s) {
        string t = "GEEKS";
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp)%mod;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalWays(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends