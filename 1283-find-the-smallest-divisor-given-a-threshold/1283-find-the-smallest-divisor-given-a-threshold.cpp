class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }
        long start = 1,end=sum;
        long ans=-1;
        while(start<=end){
            long mid = (start+end)/2;
            cout<<mid<<" ";
            long d = 0;
            for(int i=0;i<n;i++){
                d+= ceil((double)nums[i]/mid);
            }
            cout<<d<<endl;
            if(d<=threshold){
                ans = mid;
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};