class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long sum=0;
        long maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long start=maxi,end=sum;
        long ans=-1;
        while(start<=end){
            long mid  = (start+end)/2;
            long count=1,tempsum=0;
            for(int i=0;i<n;i++){
                if(tempsum+nums[i]<=mid){
                    tempsum+=nums[i];
                }
                else{
                    count++;
                    tempsum=nums[i];
                }
            }
            if(count<=m){
                ans= mid;
                end =mid-1;
            }
            else{
                start=mid+1;
            }
            
        }
        return ans;
    }
};