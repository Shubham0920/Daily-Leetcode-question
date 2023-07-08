class Solution {
public:
    static bool com(pair<int,int>a,pair<int,int>b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>ans;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            string ans="";
            for(int j=0;j<temp.size();j++){
                ans=ans+to_string(mapping[temp[j]-'0']);
            }
            int x = stoi(ans);
            v.push_back({x,i});
        }
        sort(v.begin(),v.end(),com);
        for(auto x:v){
            ans.push_back(nums[x.second]);
        }
        return ans;
    }
};