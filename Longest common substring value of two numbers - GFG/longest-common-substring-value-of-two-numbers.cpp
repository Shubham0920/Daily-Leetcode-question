//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
long long int longestCommon (long long int n1, long long int n2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long int n1, n2; cin >> n1 >> n2;

        cout << longestCommon (n1, n2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

string bindigit(long long int s){
    string ans = "";
    while(s>0){
        if(s%2)ans+='1';
        else ans+='0';
        s=s/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
long long int stoi_(string s){
    string num = s;
    long long int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
long long int longestCommon (long long int N, long long int M)
{
    // your code here
        string s = bindigit(N);
        string t = bindigit(M);
        // cout<<s<<" "<<t<<endl;
        int n = s.size();
        int m = t.size();
        vector<string> ans;
        int maxlen=INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    // ans+=s[i-1];
                    if(dp[i][j]> maxlen){
                        ans.clear();
                        maxlen = dp[i][j];
                        ans.push_back(s.substr(i-dp[i][j],dp[i][j]));
                    }
                    else if(dp[i][j] == maxlen){
                        maxlen = dp[i][j];
                        ans.push_back(s.substr(i-dp[i][j],dp[i][j]));
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    //   for(int i=0;i<=n;i++){/
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // reverse(ans.begin(),ans.end());
        long long int a = 0;
        for(int i=0;i<ans.size();i++){
            a = max(a,stoi_(ans[i]));
        }
        // cout<<ans<<endl;
        return a;
}