class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        while(true){
            if(map[o]>0){
                o = o*2;
            }
            else{
                break;
            }
        }
        return o;
    }
};