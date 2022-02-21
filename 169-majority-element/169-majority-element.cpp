class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
    int ans = 0;
    int x = 0;
    for(int i = 0;i < nums.size();i++)
    {
         mp[nums[i]]++;
    }
    for(int i = 0;i < nums.size();i++)
    {
    if(ans < mp[nums[i]])
    {
    ans = mp[nums[i]];
    x = nums[i];
    }
    }
    return x;
    }
};