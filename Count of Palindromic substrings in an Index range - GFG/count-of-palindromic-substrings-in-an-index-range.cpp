//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countPalinInRange (int n, string A, int q1, int q2);
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int q1, q2; cin >> q1 >> q2;
		cout << countPalinInRange (n, s, q1, q2) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int countPalinInRange (int m, string A, int q1, int q2)
{
    // your code here
    int mini = min(q1,q2);
    int maxi = max(q1,q2);
    string s = A.substr(mini,maxi-mini+1);
    int n = s.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    int cnt=0;
    // cout<<s<<endl;
    for(int g=0;g<s.size();g++){
        for(int i=0,j=g;j<dp.size();j++,i++){
            if(g == 0){
                dp[i][j] = 1;
            }
            else if(g==1){
                dp[i][j] = s[i] ==s[j];
            }
            else if(s[i] == s[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
            if(dp[i][j] == true){
                cnt++;
            }
        }
    }
    return cnt;
}