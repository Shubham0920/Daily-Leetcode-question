class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long sum=0;
        int n = dist.size();
        for(int i=0;i<n;i++){
            sum+= dist[i];
        }
        long start=1,end=1000000000;
        long ans= -1;
        while(start<=end){
            long mid = (start+end)/2;
            // cout<<mid<<" ";
            double d = 0;
            for(int i=0;i<n;i++){
                if(dist[i]%mid == 0){
                    d+= dist[i]/mid;
                }
                else{
                    if(i != n-1){
                        d+= dist[i]/mid+1;
                    }
                    else{
                        d+= (double)dist[i]/mid;
                    }
                }
            }
            cout<<d<<endl;
            if(d<=hour){
                // cout<<mid;
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