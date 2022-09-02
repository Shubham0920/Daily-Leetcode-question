class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]  = capacity[i] -rocks[i];
        }
        sort(ans.begin(),ans.end());
        long cnt=0;
        long  a=0;
        for(int i=0;i<n;i++){
            a+= ans[i];
            if(a<=additionalRocks){
                cnt++;
            }
        }
        return cnt;
    }
};