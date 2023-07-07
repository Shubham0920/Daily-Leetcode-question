class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<float> s;
        for(int i=0;i<nums.size()/2;i++){
            s.insert((nums[i]+nums[nums.size()-i-1])*1.0/2.0);
        }
        return s.size();
    }
};