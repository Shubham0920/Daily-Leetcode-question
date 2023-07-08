class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pre=1,suf=1;
        int n = nums.size();
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if(pre == 0){
                flag = true;
                pre = 1;
            }
            if(suf == 0){
                flag = true;
                suf = 1;
            }
            pre *= nums[i];
            suf *= nums[n-i-1];
            ans = max({ans,suf,pre});
        }
        if(flag){
            ans = max(ans,0);
        }
        return ans;
    }
};