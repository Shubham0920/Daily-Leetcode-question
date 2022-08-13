class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        if(arr[0][0] == 1){
            return 0;
        }
        int m = arr.size();
        int n = arr[0].size();
         int dp[m][n];
        bool ok=true;
        for(int i=0;i<m;i++){
            if(arr[i][0] == 0 && ok ){
                dp[i][0] = 1;
            }
            else{
                ok = false;
                dp[i][0] = 0;
            }
        }
         ok=true;
        for(int i=0;i<n;i++){
            if(arr[0][i] == 0 && ok){
                dp[0][i] = 1;
            }
            else{
                ok = false;
                dp[0][i] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++){
            if(arr[i][j] == 0){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else{
                dp[i][j] = 0;
            }
            }
        }
             return dp[m-1][n-1];
    }
};