class Solution {
public:
    set<vector<int>> s;
    void make_subset(vector<int>& nums,int i,vector<int> buf){
        if(i == nums.size()){
            sort(buf.begin(),buf.end());
            s.insert(buf);
            return ;
        }
        
        buf.push_back(nums[i]);
        make_subset(nums,i+1,buf);
        buf.pop_back();
        make_subset(nums,i+1,buf);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> buf;
        make_subset(nums,0,buf);
        vector<vector<int>> ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};