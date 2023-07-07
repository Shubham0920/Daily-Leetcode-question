class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long  int res = 0 ; 
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size();i++)
        {
           long long  int l = i+1 ,  h = nums.size()-1 , mid ,firstlower =-1 , lastupper =-1;
            // finding first element  nums[mid] + nums[i]>=lower
            while(l<=h)
            {
                mid = (l+h)/2;
                if(nums[mid] + nums[i]>=lower)
                {
                    firstlower = mid; 
                    h = mid -1;
                }
                else l = mid + 1;
            }

            l= i+1;
            h = nums.size()-1 ;
            // finding last element  nums[mid] + nums[i]<=upper
            while(l<=h)
            {
                mid = (l+h)/2;
                if(nums[mid] + nums[i]<=upper)
                {
                  lastupper = mid; 
                    l = mid  +1;
                }
                else h = mid -  1;
            }
            if(firstlower != -1 && lastupper !=-1)
            res += lastupper - firstlower + 1; 
        }
        
  

        return res ; 
    }
};