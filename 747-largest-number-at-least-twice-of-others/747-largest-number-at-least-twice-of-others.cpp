class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        
        int n = nums.size();
        vector<int> ans = nums;
        sort(nums.begin(),nums.end());
        if(nums[n-1] >= 2*nums[n-2]){
            for(int i=0;i<n;i++){
                if(ans[i] == nums[n-1]){
                    return i;
                }
            }
        }
        return -1;
    }
};