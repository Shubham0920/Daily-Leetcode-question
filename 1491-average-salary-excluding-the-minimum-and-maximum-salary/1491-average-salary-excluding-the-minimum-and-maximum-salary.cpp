class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum= 0;
        for(int i=0;i<salary.size();i++){
            sum += salary[i];
            if(salary[i]>maxi){
                maxi = salary[i];
            }
            if(salary[i]<mini){
                mini = salary[i];
            }
        }
        
        double ans = (sum-mini-maxi)/(double)(n-2);
        return ans;
    }
};