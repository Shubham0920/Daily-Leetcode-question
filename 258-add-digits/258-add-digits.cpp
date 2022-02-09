class Solution {
public:
    int addDigits(int num) {
        if(num/10 == 0){
            return num;
        }
        int res = 0;
        while(num>0){
            int x = num%10;
            res += x;
            num = num/10;
        }
        return addDigits(res);
    }
};