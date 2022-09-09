class Solution {
public:
    // vector<vector<string>> ans;
//     bool ispalindrom(string s,int st,int e){
//         while(st<e){
//             if(s[st] != s[e]){
//                 return false;
//             }
//             st++;
//             e--;
//         }
//         return true;
//     }
//     int solve(int low,string &s,vector<int> &dp){
//         // if(i==n)return 0;
//         // if(dp[i] != -1)return dp[i];
//         // int mini = INT_MAX;
//         // for(int j=i;j<n;j++){
//         //     if(ispalindrom(s,i,j)){
//         //         int cost = 1 + solve(s,j+1,n,dp);
//         //         mini  = min(mini,cost);  
//         //     }
//         // }
//         // return dp[i] = mini;
//         if(low==s.size()){
//             return 0;
//         }
        
//         if(dp[low]!=-1)return dp[low];
        
//         int currmin = INT_MAX;
        
//         for(int i = low; i<s.size(); i++){
//             if(ispalindrom(s,low, i)){
//                 currmin = min(currmin, 1+func(i+1, s, dp));
//             }
//         }
                              
//         return dp[low] = currmin;
//     }
//     // int minCut(string s) {
//     //     int n = s.size();
//     //     vector<int> dp(n,-1);
//     //     return solve(0, s, dp)-1;
//     // }
        
    bool chk(int i, int j, string&s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int func(int low, string&s, vector<int>&dp){
        if(low==s.size()){
            return 0;
        }
        
        if(dp[low]!=-1)return dp[low];
        
        int currmin = INT_MAX;
        
        for(int i = low; i<s.size(); i++){
            if(chk(low, i,s)){
                currmin = min(currmin, 1+func(i+1, s, dp));
            }
        }
                              
        return dp[low] = currmin;
    }

    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return func(0, s, dp)-1;
    }
};