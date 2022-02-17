class Solution {
public:
    void findcombination(int ind,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &temp){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            cout<<arr[ind]<<" ";
            findcombination(ind,arr,target-arr[ind],ans,temp);
            cout<<arr[ind]<<" ";
            temp.pop_back();
        }
        findcombination(ind+1,arr,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findcombination(0,candidates,target,ans,temp);
        return ans;
    }
};