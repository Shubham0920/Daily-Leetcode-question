class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long sum=0;
        for(int i=0;i<n;i++){
            sum+= candies[i];
        }
        if(sum<k){
            return 0;
        }
        long  start=1,end=sum;
        long ans = -1;
        while(start<=end){
            long mid = (start+end)/2;
            cout<<mid<<" ";
            long d=0;
            for(int i=0;i<n;i++){
                
                    if(mid!=0)d += candies[i]/mid;
            }
            cout<<d<<endl;
            if(d>=k){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};