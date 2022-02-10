class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> map;
        map[0] = 1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = ((sum%k)+k)%k;
            if(map.find(rem) != map.end()){
                count+= map.find(rem)->second;
            }
            map[rem]++;
        }
        return count;
    }
};