class Solution {
public:
    int climbStairs(int n) {
       if(n<=2) return n;
        int prev = 1;
        int temp = 2;
        int next = 2;
        for(int i=2;i<n;i++){
            temp = prev + next;
            prev = next;
            next = temp;
        }
        return temp;
    }
};