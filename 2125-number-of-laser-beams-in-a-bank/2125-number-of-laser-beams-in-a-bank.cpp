class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> a(bank.size(),0);
        int c = 0;
        for(int i=0;i<bank.size();i++){
            int cnt = 0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j] == '1'){
                    cnt++;
                }
            }
            if(cnt>0)c++;
            a[i] = cnt;
        }
        if(c<=1)return 0;
        int prev = -1;
        int ans = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] > 0 && prev == -1 ){
                prev = a[i];
            }
            else if(a[i]>0 && prev!=-1){
                ans+=a[i]*prev;
                prev = a[i];
            }
        }
        return ans;
    }
};