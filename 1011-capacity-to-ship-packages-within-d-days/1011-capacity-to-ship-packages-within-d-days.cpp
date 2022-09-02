class Solution {
public:
    bool isValid(vector<int> &weights, int &mid, int &days){
        int count = 1, sum=0;
        for(auto weight: weights){
            sum += weight;
            if(sum > mid){
                count++;
                sum=weight;
            }
        }
        return count <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity = 0;
        for(auto weight: weights) maxCapacity += weight;
        
        int low = *max_element(weights.begin(), weights.end());
        int high = maxCapacity;
        int result;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(isValid(weights, mid, days)){
                result = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return result;
    }
};