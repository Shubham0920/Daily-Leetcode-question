class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(map[target - nums[i]]>0){
                for(int j=0;j<nums.size();j++){
                    if(nums[j] == nums[i] || nums[j] == target-nums[i]){
                        ans.push_back(j);
                    }
                }
                break;
            }
            else{
                map[nums[i]]++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};