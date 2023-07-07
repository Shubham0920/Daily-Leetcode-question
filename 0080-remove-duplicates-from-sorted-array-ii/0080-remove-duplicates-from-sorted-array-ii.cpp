class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        int i=-1;
        for(int j=0;j<nums.size();j++){
            m[nums[j]]++;
            if(m[nums[j]]<=2){
                i++;
                nums[i] = nums[j];
            }
            
        }
        return i+1;
    }
};