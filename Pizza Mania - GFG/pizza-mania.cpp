//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int s,m,l,cs,cm,cl;
    int solve(int x,vector<int> &dp){
        if(x<=0) return 0;
        if(dp[x] != -1) return  dp[x];
        return dp[x] = min({cs+solve(x-s,dp),cm+solve(x-m,dp),cl+solve(x-l,dp)});
    }
    int getPizza(int X, int S, int M, int L, int CS, int CM, int CL) {
        // code here
        cs = CS;
        cm = CM;
        cl = CL;
        s = S;
        l = L;
        m = M;
        vector<int> dp(X+1,-1);
        return solve(X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int X,S,M,L,CS,CM,CL;
        
        cin>>X>>S>>M>>L>>CS>>CM>>CL;

        Solution ob;
        cout << ob.getPizza(X,S,M,L,CS,CM,CL) << endl;
    }
    return 0;
}
// } Driver Code Ends