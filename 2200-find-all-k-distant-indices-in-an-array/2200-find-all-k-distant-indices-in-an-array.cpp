class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans,ind;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == key){
                ind.push_back(i);
            }
        }
        for(int i=0;i<nums.size();i++){
            int flag = 0;
            for(int j=0;j<ind.size();j++){
                if(abs(i-ind[j])<=k && flag == 0){
                    ans.push_back(i);
                    flag = 1;
                }
            }
        }
        return ans;
        
    }
};