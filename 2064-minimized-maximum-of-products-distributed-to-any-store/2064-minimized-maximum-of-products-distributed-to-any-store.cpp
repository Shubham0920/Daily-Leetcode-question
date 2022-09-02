class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long sum=0;
        int m = quantities.size();
        for(int i=0;i<m;i++){
            sum+=quantities[i];
        }
        long start=1,end=sum;
        long ans=-1;
        while(start<=end){
            long mid = (start+end)/2;
            long d=0;
            cout<<mid<<" ";
            for(int i=0;i<m;i++){
                if(quantities[i]%mid == 0) d+= quantities[i]/mid;
                else d+= quantities[i]/mid+1;
            }
            cout<<d<<endl;
            if(d<=n){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};