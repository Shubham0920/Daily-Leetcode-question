class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(n+1);
        left_sum[0] = 0;
        for(int i=0;i<n;i++){
            left_sum[i+1] = left_sum[i] + nums[i];
        }
        int sum = left_sum[n];
        for(int i=0;i<n;i++){
            if(left_sum[i] == sum - left_sum[i]-nums[i] ){
                return i;
            }
        }
        
        return -1;
    }
};