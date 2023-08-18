//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> res;
    bool solve(int i,int j,string &s,vector<int> &answer,vector<vector<int>> &dp){
        if(i>=j)return true;
        bool found = false;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(s[i] == s[j]){
            found = true && solve(i+1,j-1,s,answer,dp);
        }
        solve(i+1,j,s,answer,dp);
        solve(i,j-1,s,answer,dp);

        if(found && (j-i+1)>=answer[2]){
            answer = {i,j,(j-i+1)};
            res.push_back(s.substr(answer[0],answer[2]));
        }
        return  dp[i][j] = found;
    }
    string longestPalin(string s) {
        int start = 0,end = 1;
        
        for(int i=1;i<s.size();i++){
            int l = i-1;
            int h = i;
            
            while(l>=0 && h<s.size() && s[l] == s[h]){
                if(h-l+1>end){
                    start = l;
                    end = h-l+1;
                }
                l--;
                h++;
            }
            l = i-1;
            h = i+1;
            
            while(l>=0 && h<s.size() && s[l] == s[h]){
                if(h-l+1>end){
                    start = l;
                    end = h-l+1;
                }
                l--;
                h++;
            }
            
        }
        
        string ans = "";
        end = start+end-1;
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends