class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int sum = target - nums[i] - nums[j];
                int start = j+1;
                int end = n-1;
                while( start < end){
                    int t = nums[start]+nums[end];
                    if(sum == t){
                        s.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(t<sum){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
            }
        }
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};