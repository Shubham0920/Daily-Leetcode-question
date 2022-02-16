class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int totalCost = 0;
        int n = cost.size();
        for(int i=0; i<n; ) {
            totalCost += cost[i];
            if(i < n-1) totalCost += cost[i+1];
            i+=3;
        }
        return totalCost;
    }
};