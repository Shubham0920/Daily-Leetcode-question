class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // cout<<nums.size()<<" "<<k<<endl;
        // return {};
        if(k>=nums.size()){
            vector<int> ans(nums.size(),-1);
            return ans;
        }
        if(k==0){
            return nums;
        }
        
        vector<int> ans(nums.size(),-1);
        long long sum = 0;
        for(int i=0;i<2*k;i++){
            sum+=nums[i];
        }
        for(int i=k;i<nums.size()-k;i++){
            sum+=nums[i+k];
            ans[i] = (sum/(2*k+1));
            sum-=nums[i-k];
            
        }
        return ans;
    }
};