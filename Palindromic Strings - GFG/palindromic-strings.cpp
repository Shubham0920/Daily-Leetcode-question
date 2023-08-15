//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int isPossiblePalindrome(string s, int K)
	{
	    // Your code goes here
	     string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int size = dp[n][n];
        return n-size <= K;
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int k;
        cin >> k;

       
	    Solution ob;
	    cout << ob.isPossiblePalindrome(s, k) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends