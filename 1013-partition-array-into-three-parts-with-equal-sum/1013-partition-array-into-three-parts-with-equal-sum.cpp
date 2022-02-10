class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum%3 != 0){
            return false;
        }
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            if(sum == total_sum/3 ){
                count++;
                sum=0;
            }
        }
        return count>=3;
        
    }
};