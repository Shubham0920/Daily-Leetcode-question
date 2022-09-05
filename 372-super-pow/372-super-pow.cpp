class Solution {
public:
    long long myPow(int x,long long n){
        if(n==0) return 1;
        if(n==1) return x%1337;
        if(n==2) return ((x%1337)*(x%1337));
        if((n&1)==0) return (myPow(myPow(x, n/2)%1337, 2))%1337;
        else return (x*myPow(myPow(x, n/2)%1337, 2))%1337;
    }
    int superPow(int a, vector<int>& b) {
        long long sum=0;
        for(int i=0;i<b.size();i++){
            sum = (sum*10 + (b[i]%1140));
            sum = sum%1140;
        }
        return myPow(a,sum)%1337;
    }
};