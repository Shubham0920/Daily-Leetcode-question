class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        set<pair<int,int>> s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j]) == k){
                    if(s.find({nums[j],nums[i]}) == s.end()){
                        s.insert(make_pair(nums[i],nums[j]));
                    }
                    
                }
            }
        }
        return s.size();
    }
};