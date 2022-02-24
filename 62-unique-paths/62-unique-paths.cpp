class Solution {
public:
    int ncr(int n, int r){
        // code here
        if(r>n-r){
            r = n-r;
        }
        long long c[r+1] ;
        memset(c,0,sizeof(c));
        c[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>0;j--){
                c[j] = (c[j]+c[j-1]);
            }
        }
        return c[r];
    }
    int uniquePaths(int m, int n) {
        return ncr(m+n-2,m-1);
        
    }
};