class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xo = 0;
        for(int i=0;i<nums.size();i++){
            xo = xo^nums[i];
        }
        long long cnt = 0;
        long long mask = xo & (~xo+1);
        cout<<mask;
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&mask){
                xor1 = xor1^nums[i];
            }
            else{
                xor2 = xor2^nums[i];
            }
        }
        return {xor1,xor2};
    }
};