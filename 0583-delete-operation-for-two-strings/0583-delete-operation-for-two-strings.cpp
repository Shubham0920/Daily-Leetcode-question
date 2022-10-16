class Solution {
public:
    int minDistance(string A, string B) {
        // string B = A;
        // reverse(B.begin(),B.end());
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