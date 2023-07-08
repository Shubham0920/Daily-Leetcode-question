class Solution {
public:
int mod=1e9+7;
int helper(int i,vector<int>&dp)
{
    if(i==0) return 1;
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    long long int take=helper(i-2,dp)%mod;
    long long int non_take=helper(i-1,dp)%mod;
    return dp[i]= (take+non_take)%mod;
}

    int countHousePlacements(int n) {
        vector<int>dp(n+2,-1);
        long long int a=helper(n+1,dp);
        return (a*a)%mod;
    }
};