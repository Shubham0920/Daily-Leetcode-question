class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            sum+= piles[i];
        }
        long start=1,end=sum;
        long ans=-1;
        while(start<=end){
            long mid = (start+end)/2;
            cout<<mid<<" ";
            int d=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid != 0)
                d+= (piles[i]/mid+1);
                else
                    d+= (piles[i]/mid);
            }
            cout<<d<<endl;
            if(d<=h){
                ans = mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};