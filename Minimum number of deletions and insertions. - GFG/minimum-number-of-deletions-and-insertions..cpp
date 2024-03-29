//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string A, string B) 
	{ 
	    // Your code goes here
	    int n = A.size();
        int m = B.size();
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    dp[i][j] = 0;
                }
                else{
                    if(A[i-1] == B[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    else{
                         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        int a = n-dp[n][m];
        int b = m - dp[n][m];
        if(a ==0){
            return b;
        }
        if(b == 0){
            return a;
        }
        return a+b;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends