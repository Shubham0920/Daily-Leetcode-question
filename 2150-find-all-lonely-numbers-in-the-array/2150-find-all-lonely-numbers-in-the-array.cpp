class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]-1] == 0 && map[nums[i]+1]== 0 && map[nums[i]] == 1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};