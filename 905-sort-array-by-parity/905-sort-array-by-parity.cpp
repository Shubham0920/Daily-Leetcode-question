class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even,odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        int j = 0;
        for(int i=0;i<even.size();i++){
            nums[j] = even[i];
            j++;
        }
        for(int i=0;i<odd.size();i++){
            nums[j] = odd[i];
            j++;
        }
        return nums;
    }
};