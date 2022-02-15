class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0 && i%2!=0){
                odd.push_back(i);
            }
            else if(nums[i]%2 != 0 && i%2==0){
                even.push_back(i);
            }
        }
        for(int i=0;i<even.size();i++){
            swap(nums[even[i]],nums[odd[i]]);
        }
        return nums;
    }
};