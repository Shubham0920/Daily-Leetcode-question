//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findMinCost(string s, string t, int costX, int costY)
	{
	    // Your code goes here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int size = dp[n][m];
        // cout<<size<<endl;
        int cost = (s.size()-size)*costX + (t.size()-size)*costY;
        
        return cost;
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends