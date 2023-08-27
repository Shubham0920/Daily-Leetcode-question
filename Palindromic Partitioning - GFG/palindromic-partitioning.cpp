//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isplaind(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string str,vector<int>&dp){
        if(i == str.size()) return 0;
        if(dp[i] != -1)return dp[i];
        int mini = INT_MAX;
        for(int k=i;k<str.size();k++){
            if(isplaind(i,k,str)){
                int cost = 1+solve(k+1,str,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] = mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size()+1,-1);
        return solve(0,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends