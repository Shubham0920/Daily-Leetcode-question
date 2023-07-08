class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int>s;
        vector<int> a;
        for(auto x:nums){
            s.insert(x);
            
        }
        for(auto x:s){
            a.push_back(x);
        }
        int ans= 0;
        for(int i=0;i<a.size()-1;i++){
            ans = max(ans,a[i+1]-a[i]);
        }
        return ans;
    }
};