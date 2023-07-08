class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int kt = k*t;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int cnt=0;
        for(int i=k;i<arr.size();i++){
            if(sum>=kt){
                cnt++;
            }
            sum-=arr[i-k];
            sum+=arr[i];
        }
        if(sum>=kt){
            cnt++;
        }
        return cnt;
    }
};