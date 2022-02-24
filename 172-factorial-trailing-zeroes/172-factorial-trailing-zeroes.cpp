class Solution {
public:
    int trailingZeroes(int n) {
        int x = 5;
        int cnt = 0;
        while(n/x>0){
            cnt += (n/x);
            x = x*5;
        }
        return cnt;
    }
};