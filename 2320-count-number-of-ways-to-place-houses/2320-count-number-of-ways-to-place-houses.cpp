
class Solution {
public:
int mod=1e9+7;
long long hope(int index1,int &n,vector<long long>&dp){
    if(index1>=n)return 1;
   if(dp[index1]!=-1)return dp[index1];
    long long way1=0;
    long long way2=0;
    way1=hope(index1+1,n,dp)%mod;
    way2=hope(index1+2,n,dp)%mod;
    return dp[index1]=(way1+way2)%mod;
}
    int countHousePlacements(int n) {
        vector<long long>dp(n+3,-1);
        long long res=hope(0,n,dp)%mod;
        long long answer=((res%mod)*(res%mod))%mod;
        return answer;
    }
};