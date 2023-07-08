class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -100000000000;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            // cout<<(sum);
        }
        for(int i=k;i<nums.size();i++){
            if((sum*1.0)/k>ans){
                ans = (sum*1.0)/k;
            }
            sum-=nums[i-k];
            sum+=nums[i];
        }
        if((sum*1.0)/k>ans){
            // cout<<(sum);
                ans = (sum*1.0)/k;
        }
        return ans;
    }
};