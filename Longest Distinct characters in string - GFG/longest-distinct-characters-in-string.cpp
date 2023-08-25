//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
        int i = 0;
        int j = 0;
        int m[26] = {0};
        int ans = INT_MIN;
        while(j<s.size()){
            if(m[s[j]-'a']>=1){
                while(m[s[j]-'a']>=1){
                    m[s[i]-'a']--;
                    i++;
                }
                m[s[j]-'a']++;
                ans = max(ans,j-i+1);
            }
            else{
                m[s[j]-'a']++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
}