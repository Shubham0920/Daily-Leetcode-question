class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> equal;
        vector<int> more;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                more.push_back(nums[i]);
            }
            else{
                equal.push_back(nums[i]);
            }
        }
        int j=0;
        for(int i=0;i<less.size();i++){
            nums[j] = less[i];
            j++;
        }
        for(int i=0;i<equal.size();i++){
            nums[j] = equal[i];
            j++;
        }
        for(int i=0;i<more.size();i++){
            nums[j] = more[i];
            j++;
        }
        return nums;
    }
};