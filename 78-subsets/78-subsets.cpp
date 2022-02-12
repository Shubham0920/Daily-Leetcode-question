class Solution {
public:
    vector<vector<int>> ans;
    void make_subset(vector<int>& nums,int i,vector<int> buf){
        if(i == nums.size()){
            ans.push_back(buf);
            return ;
        }
        
        buf.push_back(nums[i]);
        make_subset(nums,i+1,buf);
        buf.pop_back();
        make_subset(nums,i+1,buf);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> buf;
        make_subset(nums,0,buf);
        return ans;
    }
};