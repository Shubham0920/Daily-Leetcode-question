class Solution {
public:
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(int i=0;i<nums.size();i++){
            maxor = maxor | nums[i];
        }
        int count=0;
        int n=nums.size();
        unsigned int pow_set_size = pow(2, n);
        int counter, j;
 
        for(counter = 0; counter < pow_set_size; counter++)
        {
            int mxor = 0;
        for(j = 0; j < n; j++)
        {
            if(counter & (1 << j))
                mxor |= nums[j];
        }
        if(mxor == maxor)
            count++;
        }
        return count;
    }
};